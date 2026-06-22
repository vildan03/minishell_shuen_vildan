import subprocess
import threading
import queue
import time
import sys
import os
import re
import signal

class StreamQueueReader(threading.Thread):
    def __init__(self, stream):
        super().__init__()
        self.stream = stream
        self.queue = queue.Queue()
        self.daemon = True
        self.stop_event = threading.Event()

    def run(self):
        try:
            for line in iter(self.stream.readline, ''):
                self.queue.put(line)
        except Exception:
            pass

def get_heredoc_limiters(cmd):
    matches = re.findall(r'<<\s*([^<>\s|;&()]+)', cmd)
    limiters = []
    for m in matches:
        if (m.startswith('"') and m.endswith('"')) or (m.startswith("'") and m.endswith("'")):
            m = m[1:-1]
        limiters.append(m)
    return limiters

def might_consume_stdin(cmd):
    normalized = cmd.replace('\\n', '\n')
    pipelines = re.split(r'\n|&&|\|\||;', normalized)
    for pipe in pipelines:
        pipe = pipe.strip()
        if not pipe:
            continue
        first_cmd = pipe.split('|')[0].strip()
        words = first_cmd.split()
        if not words:
            continue
        first_word = words[0]
        first_word = first_word.strip('\'"')
        if first_word in ["cat", "grep", "wc", "head", "tail", "more", "less", "awk", "sed"]:
            if '<' not in first_cmd:
                return True
    return False

def force_permissions(binary_path):
    try:
        os.chmod(binary_path, 0o755)
    except Exception:
        pass

def start_shell(binary_path, is_bash=False):
    if is_bash:
        args = ["bash", "--norc", "--noprofile"]
    else:
        force_permissions(binary_path)
        args = [binary_path]
        
    proc = subprocess.Popen(
        args,
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        bufsize=1,
        close_fds=True
    )
    
    stdout_reader = StreamQueueReader(proc.stdout)
    stderr_reader = StreamQueueReader(proc.stderr)
    stdout_reader.start()
    stderr_reader.start()
    
    return proc, stdout_reader, stderr_reader

def run_cmd_in_proc(proc, stdout_reader, stderr_reader, command, index, timeout=10):
    status_sentinel = f"__SENT_STATUS_{index}__"
    
    formatted_cmd = command.replace('\\n', '\n')
    limiters = get_heredoc_limiters(formatted_cmd)
    
    # Build input text
    input_text = formatted_cmd + "\n"
    for lim in limiters:
        input_text += f"{lim}\n"
    input_text += f"echo {status_sentinel} $?\n"
    
    try:
        proc.stdin.write(input_text)
        proc.stdin.flush()
    except IOError:
        return "", "", proc.poll(), False, True
        
    stdout_lines = []
    stderr_lines = []
    start_time = time.time()
    timed_out = False
    exited = False
    status_code = None
    
    while True:
        ret = proc.poll()
        if ret is not None:
            exited = True
            break
            
        if time.time() - start_time > timeout:
            timed_out = True
            break
            
        try:
            line = stdout_reader.queue.get(timeout=0.02)
            stdout_lines.append(line)
            if status_sentinel in line:
                try:
                    parts = line.strip().split()
                    status_code = int(parts[-1])
                except Exception:
                    pass
                break
        except queue.Empty:
            pass
            
    # Drain stderr
    time.sleep(0.02)
    while True:
        try:
            line = stderr_reader.queue.get_nowait()
            stderr_lines.append(line)
        except queue.Empty:
            break
            
    # If exited, drain stdout
    if exited:
        while True:
            try:
                line = stdout_reader.queue.get_nowait()
                stdout_lines.append(line)
            except queue.Empty:
                break
        status_code = proc.poll()
        
    full_stdout = "".join(stdout_lines)
    full_stderr = "".join(stderr_lines)
    
    if status_code is None and status_sentinel in full_stdout:
        try:
            for l in full_stdout.splitlines():
                if status_sentinel in l:
                    parts = l.strip().split()
                    status_code = int(parts[-1])
                    break
        except Exception:
            pass
            
    # Clean sentinel
    clean_lines = []
    for l in full_stdout.splitlines(keepends=True):
        if status_sentinel in l:
            continue
        clean_lines.append(l)
    clean_stdout = "".join(clean_lines)
    
    return clean_stdout, full_stderr, status_code, timed_out, exited

def run_cmd_one_shot(binary_path, command, is_bash=False, timeout=10):
    """Fallback run in a fresh one-shot process for dangerous commands."""
    if is_bash:
        args = ["bash", "--norc", "--noprofile"]
    else:
        force_permissions(binary_path)
        args = [binary_path]
        
    formatted_cmd = command.replace('\\n', '\n')
    
    try:
        proc = subprocess.run(
            args,
            input=formatted_cmd + "\n",
            text=True,
            capture_output=True,
            timeout=timeout
        )
        return proc.stdout, proc.stderr, proc.returncode, False, False
    except subprocess.TimeoutExpired:
        return "", "", -1, True, False
    except Exception:
        return "", "", -1, False, True

def clean_env_output(out):
    lines = []
    exclude_prefixes = [
        "ANTIGRAVITY_", "NIX_", "SSH_", "DBUS_", "GTK_", "PYTHON", "XDG_", "LESS", "GDK_", "GIO_", "KPACKAGE_", 
        "STARSHIP_", "LANG", "TERM", "LOGNAME", "USER", "HOME", "PATH", "HOST_PATH", "INFOPATH", "LIBEXEC_PATH", 
        "TERMINFO_DIRS", "TZDIR", "CONFIG_SHELL", "SHELL", "IN_NIX_SHELL", "SOURCE_DATE_EPOCH", "AS", "AR", "CC", 
        "CXX", "LD", "NM", "OBJCOPY", "OBJDUMP", "RANLIB", "READELF", "SIZE", "STRINGS", "STRIP", "stdenv", "system", 
        "builder", "buildInputs", "nativeBuildInputs", "propagatedBuildInputs", "propagatedNativeBuildInputs", 
        "outputs", "out", "patches", "configureFlags", "cmakeFlags", "mesonFlags", "strictDeps", "enableParallelBuilding", 
        "enableParallelChecking", "enableParallelInstalling", "doCheck", "doInstallCheck", "passAsFile", 
        "buildCommandPath", "__structuredAttrs", "__ETC_PROFILE_DONE", "__HM_SESS_VARS_SOURCED", 
        "__HM_ZSH_SESS_VARS_SOURCED", "__NIXOS_SET_ENVIRONMENT_DONE", "EDITOR", "MICRO_TRUECOLOR", 
        "NIXPKGS_CONFIG", "FZF_DEFAULT_COMMAND", "OLDPWD", "PWD", "SHLVL", "_"
    ]
    for l in out.splitlines():
        cleaned_line = l
        if cleaned_line.startswith("declare -x "):
            cleaned_line = cleaned_line[len("declare -x "):]
        elif cleaned_line.startswith("export "):
            cleaned_line = cleaned_line[len("export "):]
            
        var_name = cleaned_line.split('=')[0]
        if var_name in exclude_prefixes or any(var_name.startswith(p) for p in exclude_prefixes):
            continue
        lines.append(l)
    return "\n".join(sorted(lines))

def compare_outputs(bash_out, bash_err, bash_status, ms_out, ms_err, ms_status, command):
    is_env_cmd = "env" in command or "export" in command
    if is_env_cmd:
        bash_norm_out = clean_env_output(bash_out)
        ms_norm_out = clean_env_output(ms_out)
    else:
        bash_norm_out = bash_out.strip()
        ms_norm_out = ms_out.strip()
        
    out_match = (bash_norm_out == ms_norm_out)
    
    bash_has_err = bool(bash_err.strip())
    ms_has_err = bool(ms_err.strip())
    err_match = (bash_has_err == ms_has_err)
    status_match = (bash_status == ms_status)
    
    mismatches = []
    if not out_match:
        mismatches.append(f"stdout mismatch:\n  BASH:\n{bash_out.strip()}\n  MINISHELL:\n{ms_out.strip()}")
    if not err_match:
        mismatches.append(f"stderr mismatch:\n  BASH stderr empty? {not bash_has_err} (content: {bash_err.strip()})\n  MINISHELL stderr empty? {not ms_has_err} (content: {ms_err.strip()})")
    if not status_match:
        mismatches.append(f"exit status mismatch: BASH={bash_status}, MINISHELL={ms_status}")
        
    return mismatches

def test_interactive_signals():
    import pty
    import termios
    import select
    
    print("\n--- Starting Interactive Signal Tests ---")
    failures = []
    
    # 1. Ctrl-C and Ctrl-\\ in empty prompt
    master_fd, slave_fd = pty.openpty()
    attrs = termios.tcgetattr(master_fd)
    attrs[3] = attrs[3] & ~termios.ECHO
    termios.tcsetattr(master_fd, termios.TCSANOW, attrs)
    
    proc = subprocess.Popen(
        ["./minishell"],
        stdin=slave_fd,
        stdout=slave_fd,
        stderr=slave_fd,
        text=True,
        close_fds=True
    )
    os.close(slave_fd)
    time.sleep(0.2)
    
    os.write(master_fd, b"hello_test")
    time.sleep(0.1)
    os.kill(proc.pid, signal.SIGINT)
    time.sleep(0.2)
    os.write(master_fd, b"\n")
    time.sleep(0.2)
    
    r, _, _ = select.select([master_fd], [], [], 0.5)
    output = ""
    if r:
        try:
            output = os.read(master_fd, 4096).decode('utf-8', errors='ignore')
        except OSError:
            pass
            
    if "hello_test: command not found" in output or "hello_test:" in output:
        failures.append("Ctrl-C failed to clear input buffer (command executed on Enter)")
        
    os.kill(proc.pid, signal.SIGQUIT)
    time.sleep(0.2)
    
    if proc.poll() is not None:
        failures.append(f"SIGQUIT (Ctrl-\\) terminated minishell (exit code {proc.poll()})")
    else:
        try:
            os.write(master_fd, b"exit\n")
            proc.wait(timeout=1)
        except Exception:
            proc.kill()
            
    # 2. SIGINT during blocking command
    master_fd, slave_fd = pty.openpty()
    attrs = termios.tcgetattr(master_fd)
    attrs[3] = attrs[3] & ~termios.ECHO
    termios.tcsetattr(master_fd, termios.TCSANOW, attrs)
    
    proc = subprocess.Popen(
        ["./minishell"],
        stdin=slave_fd,
        stdout=slave_fd,
        stderr=slave_fd,
        text=True,
        close_fds=True
    )
    os.close(slave_fd)
    time.sleep(0.2)
    
    os.write(master_fd, b"cat\n")
    time.sleep(0.2)
    os.write(master_fd, b"hello cat\n")
    time.sleep(0.2)
    os.kill(proc.pid, signal.SIGINT)
    time.sleep(0.2)
    
    if proc.poll() is not None:
        failures.append(f"SIGINT during blocking command terminated minishell itself (exit code {proc.poll()})")
    else:
        os.write(master_fd, b"pwd\n")
        time.sleep(0.2)
        r, _, _ = select.select([master_fd], [], [], 0.5)
        output = ""
        if r:
            try:
                output = os.read(master_fd, 4096).decode('utf-8', errors='ignore')
            except OSError:
                pass
        if "42_minishell" not in output and "pwd" not in output:
            failures.append("Shell unresponsive after SIGINT interrupt on blocking command")
            
        try:
            os.write(master_fd, b"exit\n")
            proc.wait(timeout=1)
        except Exception:
            proc.kill()
            
    return failures

def run_valgrind_leak_check(binary_path, tests):
    print("\n--- Running Valgrind Leak Check ---")
    supp_path = "readline.supp"
    force_permissions(binary_path)
    
    test_input_file = "valgrind_input.tmp"
    with open(test_input_file, "w") as f:
        for cmd in tests:
            formatted_cmd = cmd.replace('\\n', '\n')
            f.write(formatted_cmd + "\n")
            
    valgrind_cmd = [
        "valgrind",
        "--leak-check=full",
        "--show-leak-kinds=all",
        f"--suppressions={supp_path}",
        "--log-file=valgrind_report.tmp",
        binary_path
    ]
    
    try:
        with open(test_input_file, "r") as infile:
            subprocess.run(valgrind_cmd, stdin=infile, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, timeout=45)
    except subprocess.TimeoutExpired:
        print("Valgrind execution timed out (limit 45s)")
    except Exception as e:
        print(f"Error executing Valgrind: {e}")
        
    leaks_summary = ""
    errors_found = False
    if os.path.exists("valgrind_report.tmp"):
        with open("valgrind_report.tmp", "r") as f:
            report = f.read()
            if "definitely lost:" in report:
                def_lost_match = re.search(r"definitely lost:\s+([0-9,]+)\s+bytes", report)
                if def_lost_match and int(def_lost_match.group(1).replace(',', '')) > 0:
                    errors_found = True
            if "ERROR SUMMARY: [1-9]" in report:
                errors_found = True
                
            if errors_found:
                summary_match = re.search(r"==\d+== LEAK SUMMARY:.*", report, re.DOTALL)
                if summary_match:
                    leaks_summary = summary_match.group(0)
                else:
                    leaks_summary = report
                
    try: os.remove(test_input_file)
    except Exception: pass
    try: os.remove("valgrind_report.tmp")
    except Exception: pass
    
    return errors_found, leaks_summary

def is_out_of_scope(cmd):
    # 1. Contains semicolon
    if ';' in cmd:
        return True, "Semicolon ';' is not required by the subject"
    # 2. Contains backslash
    if '\\' in cmd:
        return True, "Backslash '\\' is not required by the subject"
    # 3. Local variable assignment (e.g. ABC=hola or 4ABC=hola)
    # but not inside export/unset (e.g. export ABC=hola)
    if not cmd.startswith("export ") and not cmd.startswith("unset "):
        for segment in re.split(r'\s+|\||&&|\|\|', cmd):
            if re.match(r'^[a-zA-Z_][a-zA-Z0-9_]*=', segment):
                return True, "Local variable assignment without export is not required"
    # 4. env with arguments
    if cmd.startswith("env ") and len(cmd.split()) > 1:
        first_part = cmd.split('|')[0].strip()
        if len(first_part.split()) > 1:
            return True, "env does not require arguments or options"
    # 5. pwd with options
    if cmd.startswith("pwd ") and len(cmd.split()) > 1:
        first_part = cmd.split('|')[0].strip()
        args = first_part.split()[1:]
        if any(arg.startswith('-') for arg in args):
            return True, "pwd does not require options"
    # 6. Tilde expansion
    if '~' in cmd:
        return True, "Tilde '~' expansion is not required"
    # 7. Wildcard matching outside the current working directory
    for word in cmd.split():
        if '*' in word:
            # Skip if it is the special parameter $*
            if '$*' in word:
                continue
            if '/' in word or '$HOME' in word or '$USER' in word or '..' in word:
                return True, "Wildcard matching outside current directory is not required"
    # 8. Character class wildcards []
    if '[' in cmd or ']' in cmd:
        return True, "Character class wildcards '[]' are not required by the subject"
    # 9. Internal shell variables like $UID
    if '$UID' in cmd:
        return True, "Internal shell variable '$UID' is not exported to minishell"
    # 10. Special parameters like $*
    if '$*' in cmd:
        return True, "Special parameter '$*' is not required by the subject"
    # 11. export/unset with option flags starting with -
    if cmd.startswith("export ") or cmd.startswith("unset "):
        parts = cmd.split()
        if len(parts) > 1 and any(arg.startswith('-') for arg in parts[1:]):
            return True, "export/unset options/flags are not required by the subject"
    # 12. export with append +=
    if "+=" in cmd and cmd.startswith("export "):
        return True, "export with append operator '+=' is out of scope"
    # 13. Background operator &
    clean_cmd = cmd.replace("&&", "")
    if '&' in clean_cmd:
        return True, "Background operator '&' is not required by the subject"
    # 14. Non-required history builtin
    if "history" in cmd.split():
        return True, "history builtin is not required by the subject"
    # 15. cd with multiple arguments or options
    if cmd.startswith("cd ") and len(cmd.split()) > 2:
        return True, "cd with multiple arguments is not required by the subject"
    if cmd.startswith("cd ") and any(arg.startswith('-') for arg in cmd.split()[1:]):
        return True, "cd options/flags are not required by the subject"
    # 20. cd with wildcard
    if cmd.startswith("cd ") and '*' in cmd:
        return True, "cd with wildcard is not required by the subject"
    # 16. Non-standard space around equals in export
    if "export " in cmd:
        if re.search(r'export\s+[^=]+\s+=', cmd) or re.search(r'export\s+[^=]+=\s+', cmd):
            return True, "export with spaces around '=' is not standard assignment syntax"
    # 17. exit with multiple arguments
    if cmd.startswith("exit ") and len(cmd.split()) > 2:
        return True, "exit with multiple arguments is not required by the subject"
    # 18. Here strings <<<
    if '<<<' in cmd:
        return True, "Here strings '<<<' are not required by the subject"
    # 19. Heredoc with complex delimiter containing quotes or dollar signs
    if "<<" in cmd:
        matches = re.findall(r'<<\s*([^<>\s|;&()]+)', cmd)
        for m in matches:
            if '"' in m or "'" in m or '$' in m:
                return True, "Heredoc with quotes or dollar sign in delimiter is out of scope"
                
    return False, ""

def write_failure_item(f, f_item):
    f.write(f"### Mismatch for Command: `{f_item['command']}`\n")
    f.write(f"**Reason**: {f_item['reason']}\n\n")
    
    f.write("#### 💻 BASH baseline\n")
    f.write(f"- **Exit Status**: `{f_item['bash_status']}`\n")
    if f_item['bash_out'].strip():
        f.write("- **Stdout**:\n")
        f.write("  ```\n")
        f.write("  " + f_item['bash_out'].strip().replace("\n", "\n  ") + "\n")
        f.write("  ```\n")
    else:
        f.write("- **Stdout**: *(Empty)*\n")
        
    if f_item['bash_err'].strip():
        f.write("- **Stderr**:\n")
        f.write("  ```\n")
        f.write("  " + f_item['bash_err'].strip().replace("\n", "\n  ") + "\n")
        f.write("  ```\n")
    else:
        f.write("- **Stderr**: *(Empty)*\n")
    f.write("\n")
    
    f.write("#### 🐚 MINISHELL (`./minishell`) tested\n")
    f.write(f"- **Exit Status**: `{f_item['ms_status']}`\n")
    if f_item['ms_out'].strip():
        f.write("- **Stdout**:\n")
        f.write("  ```\n")
        f.write("  " + f_item['ms_out'].strip().replace("\n", "\n  ") + "\n")
        f.write("  ```\n")
    else:
        f.write("- **Stdout**: *(Empty)*\n")
        
    if f_item['ms_err'].strip():
        f.write("- **Stderr**:\n")
        f.write("  ```\n")
        f.write("  " + f_item['ms_err'].strip().replace("\n", "\n  ") + "\n")
        f.write("  ```\n")
    else:
        f.write("- **Stderr**: *(Empty)*\n")
    f.write("\n---\n\n")

def main():
    test_file = "tests.txt"
    binary_path = "./minishell"
    
    if not os.path.exists(binary_path):
        print(f"Error: {binary_path} does not exist. Run make first.")
        sys.exit(1)
        
    try:
        with open(test_file, 'r', encoding='utf-8', errors='ignore') as f:
            tests = [line.strip() for line in f if line.strip() and not line.strip().startswith('#')]
    except FileNotFoundError:
        print(f"Error: {test_file} not found.")
        sys.exit(1)
        
    print(f"Loaded {len(tests)} test cases.")
    
    bash_proc, bash_out_reader, bash_err_reader = start_shell(binary_path, is_bash=True)
    ms_proc, ms_out_reader, ms_err_reader = start_shell(binary_path, is_bash=False)
    
    failures = []
    crashes = []
    timeouts = []
    passed_count = 0
    
    print("\n--- Running Persistent Tests (all in a single shell process) ---")
    
    for idx, cmd in enumerate(tests):
        force_permissions(binary_path)
        
        # Check if out of scope before running
        out_of_scope_flag, detail_msg = is_out_of_scope(cmd)
        if out_of_scope_flag:
            failures.append({
                "command": cmd,
                "bash_out": "", "bash_err": "", "bash_status": 0,
                "ms_out": "", "ms_err": "", "ms_status": 0,
                "reason": f"Skipped: {detail_msg}",
                "is_out_of_scope": True
            })
            continue
            
        use_one_shot = might_consume_stdin(cmd)
        
        if use_one_shot:
            bash_out, bash_err, bash_status, bash_to, bash_exit = run_cmd_one_shot(binary_path, cmd, is_bash=True)
            ms_out, ms_err, ms_status, ms_to, ms_exit = run_cmd_one_shot(binary_path, cmd, is_bash=False)
        else:
            ms_died = ms_proc.poll() is not None
            bash_died = bash_proc.poll() is not None
            if ms_died or bash_died:
                if ms_died:
                    status = ms_proc.poll()
                    is_exit_cmd = "exit" in cmd or (idx > 0 and "exit" in tests[idx-1])
                    if not is_exit_cmd:
                        crashes.append({
                            "command": cmd,
                            "exit_code": status,
                            "reason": f"Shell process died unexpectedly with status {status}"
                        })
                # Restart both to keep working directory in sync
                if ms_proc.poll() is None:
                    ms_proc.kill()
                if bash_proc.poll() is None:
                    bash_proc.kill()
                ms_proc, ms_out_reader, ms_err_reader = start_shell(binary_path, is_bash=False)
                bash_proc, bash_out_reader, bash_err_reader = start_shell(binary_path, is_bash=True)
                
            bash_out, bash_err, bash_status, bash_to, bash_exit = run_cmd_in_proc(
                bash_proc, bash_out_reader, bash_err_reader, cmd, idx
            )
            ms_out, ms_err, ms_status, ms_to, ms_exit = run_cmd_in_proc(
                ms_proc, ms_out_reader, ms_err_reader, cmd, idx
            )
            
        if ms_to or bash_to:
            timeouts.append({"command": cmd, "type": "minishell" if ms_to else "bash"})
            if not use_one_shot:
                if ms_proc.poll() is None:
                    ms_proc.kill()
                if bash_proc.poll() is None:
                    bash_proc.kill()
                ms_proc, ms_out_reader, ms_err_reader = start_shell(binary_path, is_bash=False)
                bash_proc, bash_out_reader, bash_err_reader = start_shell(binary_path, is_bash=True)
            continue
            
        if ms_exit and ms_status != bash_status:
            if ms_status is not None and (ms_status < 0 or ms_status in [139, 134]):
                crashes.append({
                    "command": cmd,
                    "exit_code": ms_status,
                    "reason": f"Minishell crashed with status {ms_status}"
                })
            else:
                failures.append({
                    "command": cmd,
                    "bash_out": bash_out, "bash_err": bash_err, "bash_status": bash_status,
                    "ms_out": ms_out, "ms_err": ms_err, "ms_status": ms_status,
                    "reason": f"Minishell exited unexpectedly with status {ms_status} instead of {bash_status}"
                })
            if not use_one_shot:
                if ms_proc.poll() is None:
                    ms_proc.kill()
                if bash_proc.poll() is None:
                    bash_proc.kill()
                ms_proc, ms_out_reader, ms_err_reader = start_shell(binary_path, is_bash=False)
                bash_proc, bash_out_reader, bash_err_reader = start_shell(binary_path, is_bash=True)
            continue
            
        mismatches = compare_outputs(bash_out, bash_err, bash_status, ms_out, ms_err, ms_status, cmd)
        if mismatches:
            # Check if this is a wildcard sorting mismatch (same words, different order)
            is_sorting_diff = False
            if '*' in cmd and not bash_err.strip() and not ms_err.strip() and bash_status == ms_status:
                bash_words = bash_out.strip().split()
                ms_words = ms_out.strip().split()
                if len(bash_words) == len(ms_words) and sorted(bash_words) == sorted(ms_words):
                    is_sorting_diff = True
                    
            failures.append({
                "command": cmd,
                "bash_out": bash_out, "bash_err": bash_err, "bash_status": bash_status,
                "ms_out": ms_out, "ms_err": ms_err, "ms_status": ms_status,
                "reason": "; ".join(mismatches),
                "is_sorting_diff": is_sorting_diff
            })
        else:
            passed_count += 1
            
        if (idx + 1) % 50 == 0:
            print(f"Processed {idx+1}/{len(tests)} tests... Passed so far: {passed_count}")
            
    print(f"\nCompleted {len(tests)} test cases.")
    
    signal_failures = test_interactive_signals()
    leaks_found, leaks_summary = run_valgrind_leak_check(binary_path, tests)
    
    if ms_proc.poll() is None: ms_proc.kill()
    if bash_proc.poll() is None: bash_proc.kill()
    
    # Classify failures into required vs out-of-scope
    required_failures = []
    outofscope_failures = []
    for f_item in failures:
        out_of_scope_flag, detail_msg = is_out_of_scope(f_item['command'])
        if out_of_scope_flag:
            f_item['reason'] = f"{f_item['reason']} (Note: {detail_msg})"
            outofscope_failures.append(f_item)
        elif f_item.get('is_sorting_diff'):
            f_item['reason'] = f"{f_item['reason']} (Note: Wildcard sorting order difference (ASCII vs dictionary) is out of scope)"
            outofscope_failures.append(f_item)
        else:
            required_failures.append(f_item)
            
    # Write report MD
    paths = [
        "/home/kershuen/.gemini/antigravity-cli/brain/c5f986b2-c14c-4635-8d99-58e012609a85/failed_test.md",
        "/home/kershuen/42_minishell/failed_test.md"
    ]
    for path in paths:
        try:
            with open(path, "w") as f:
                f.write("# Minishell Test Report\n\n")
                f.write("## 📊 Execution Summary\n")
                f.write(f"- **Total Tests Run**: {len(tests)}\n")
                f.write(f"- **Passed**: {passed_count}\n")
                f.write(f"- **Required Feature Failures**: {len(required_failures)}\n")
                f.write(f"- **Out of Scope Differences**: {len(outofscope_failures)}\n")
                f.write(f"- **Crashes**: {len(crashes)}\n")
                f.write(f"- **Timeouts (Hangs)**: {len(timeouts)}\n")
                f.write(f"- **Signal Handling Failures**: {len(signal_failures)}\n")
                f.write(f"- **Memory/FD Leaks Found**: {'Yes' if leaks_found else 'No'}\n\n")
                
                if signal_failures:
                    f.write("## 🚨 Signal Handling Failures\n")
                    for sf in signal_failures:
                        f.write(f"- `[KO]` {sf}\n")
                    f.write("\n")
                    
                if leaks_found and leaks_summary:
                    f.write("## 💧 Valgrind Leak Summary\n")
                    f.write("```\n")
                    f.write(leaks_summary.strip() + "\n")
                    f.write("```\n\n")
                    
                if crashes:
                    f.write("## 💥 Crashes\n")
                    f.write("| Test Command | Exit Code | Reason |\n")
                    f.write("| :--- | :--- | :--- |\n")
                    for c in crashes:
                        f.write(f"| `{c['command']}` | `{c['exit_code']}` | {c['reason']} |\n")
                    f.write("\n")
                    
                if timeouts:
                    f.write("## ⏳ Timeouts / Hangs\n")
                    for t in timeouts:
                        f.write(f"- `{t['command']}`\n")
                    f.write("\n")
                    
                f.write("## ❌ Required Feature Failures\n")
                f.write("> [!IMPORTANT]\n")
                f.write("> The failures below correspond to standard requirements and bonuses of the project. **These must be fixed.**\n\n")
                if required_failures:
                    for f_item in required_failures:
                        write_failure_item(f, f_item)
                else:
                    f.write("*None! All mandatory and bonus requirements passed successfully!* 🎉\n\n")
                    
                f.write("## ℹ️ Out of Scope Differences (Non-Required Features)\n")
                f.write("> [!NOTE]\n")
                f.write("> The mismatches below involve features explicitly excluded by the subject (e.g. backslashes, semicolons, tildes, or local assignments). **You are NOT required to fix these.**\n\n")
                for f_item in outofscope_failures:
                    write_failure_item(f, f_item)
                    
            print(f"Test report written to {path}")
        except Exception as e:
            print(f"Failed to write to {path}: {e}")
            
    sys.exit(1 if (required_failures or crashes or timeouts or signal_failures or leaks_found) else 0)

if __name__ == "__main__":
    main()
