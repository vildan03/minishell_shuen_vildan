import subprocess
import sys
import os

# --- Configuration ---
TEST_FILE = "tests.txt"
MINISHELL_PATH = "./minishell"
SUPP_FILE = "read.supp"
TIMEOUT_SECS = 5

# ANSI Colors for terminal output
GREEN = '\033[92m'
RED = '\033[91m'
YELLOW = '\033[93m'
RESET = '\033[0m'

def run_cmd(executable, command, use_valgrind=False):
    """Runs a command in the target executable and captures results."""
    
    if use_valgrind:
        exec_list = [
            "valgrind", "--leak-check=full", "--show-leak-kinds=all",
            f"--suppressions={SUPP_FILE}", "--error-exitcode=100", "-q",
            MINISHELL_PATH
        ]
    elif executable == "bash":
        # Force Bash into POSIX mode for a fairer comparison
        exec_list = ["bash", "--posix"]
    else:
        exec_list = [MINISHELL_PATH]
        
    try:
        # Safely convert literal '\n' text into actual newlines for execution
        formatted_cmd = command.replace('\\n', '\n')
        
        process = subprocess.run(
            exec_list,
            input=formatted_cmd + "\n",
            text=True,
            capture_output=True,
            timeout=TIMEOUT_SECS,
            errors='replace'
        )
        return {
            "stdout": process.stdout,
            "stderr": process.stderr,
            "exit_code": process.returncode,
            "timeout": False
        }
    except subprocess.TimeoutExpired:
        return {"stdout": "", "stderr": "", "exit_code": -1, "timeout": True}
    except Exception as e:
        print(f"{RED}Script Execution Error on command '{command}': {e}{RESET}")
        return {"stdout": "", "stderr": "", "exit_code": -1, "timeout": False}

def main():
    # 1. Sanity Checks before running
    if not os.path.exists(MINISHELL_PATH):
        print(f"{RED}CRITICAL ERROR: Cannot find '{MINISHELL_PATH}'. Did you run 'make'?{RESET}")
        return
    
    # Initial permission fix just in case it's locked before the script even starts
    try:
        os.chmod(MINISHELL_PATH, 0o755)
    except Exception:
        pass

    if not os.access(MINISHELL_PATH, os.X_OK):
        print(f"{RED}CRITICAL ERROR: '{MINISHELL_PATH}' is not executable. Run 'chmod +x minishell'.{RESET}")
        return

    # 2. Read file with encoding protection
    try:
        with open(TEST_FILE, 'r', encoding='utf-8', errors='ignore') as f:
            tests = [line.strip() for line in f.readlines() if line.strip() and not line.startswith('#')]
    except FileNotFoundError:
        print(f"{RED}CRITICAL ERROR: {TEST_FILE} not found.{RESET}")
        return

    passed = 0
    total = len(tests)

    print(f"Starting test suite: {total} tests...\n")
    print("-" * 50)

    for cmd in tests:
        # --- Force restore permissions before EACH run ---
        # This prevents tests like 'chmod 000 minishell' from breaking the suite

        # 1. Reset and run Bash
        try: os.chmod(MINISHELL_PATH, 0o755)
        except Exception: pass
        bash_res = run_cmd("bash", cmd)

        # 2. Reset and run Minishell (Bash might have locked it!)
        try: os.chmod(MINISHELL_PATH, 0o755)
        except Exception: pass
        ms_res = run_cmd("minishell", cmd)
        
        # 3. Reset and run Valgrind (Minishell might have locked it!)
        try: os.chmod(MINISHELL_PATH, 0o755)
        except Exception: pass
        valgrind_res = run_cmd("minishell", cmd, use_valgrind=True)

        # Evaluation
        is_timeout = ms_res["timeout"]
        if "env" in cmd or "export" in cmd:
            bash_out = "\n".join(sorted(x for x in bash_res["stdout"].splitlines() if not (x.startswith("_=") or x.startswith("export _=") or x.startswith("declare -x _="))))
            ms_out = "\n".join(sorted(x for x in ms_res["stdout"].splitlines() if not (x.startswith("_=") or x.startswith("export _=") or x.startswith("declare -x _="))))
            out_match = (bash_out == ms_out)
        else:
            out_match = (bash_res["stdout"] == ms_res["stdout"])
        exit_match = (bash_res["exit_code"] == ms_res["exit_code"])
        has_leaks = valgrind_res["exit_code"] == 100
        
        status_tag = f"{GREEN}[OK]{RESET}" if (out_match and exit_match and not is_timeout) else f"{RED}[KO]{RESET}"
        leak_tag = f"{RED}[LEAKS]{RESET}" if has_leaks else f"{GREEN}[NO LEAKS]{RESET}"
        
        if is_timeout:
            status_tag = f"{YELLOW}[TIMEOUT]{RESET}"
            
        print(f"{status_tag} {leak_tag} : {cmd}")
        if not (out_match and exit_match and not is_timeout):
            pass # We removed the extra print statements here!
        else:
            passed += 1
    print("=" * 50)
    print(f"RESULTS: {passed}/{total} tests passed.")

if __name__ == "__main__":
    main()
