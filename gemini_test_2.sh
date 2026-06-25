#!/bin/bash

# --- Configuration ---
MINISHELL="./minishell"
BASH_EXEC="bash"
VALGRIND="valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --errors-for-leak-kinds=all --quiet"
TIMEOUT="timeout 2s" # Prevents hanging on unclosed pipes

# --- Colors & Counters ---
GREEN="\033[32m"
RED="\033[31m"
YELLOW="\033[33m"
BLUE="\033[34m"
RESET="\033[0m"
TOTAL=0; PASSED=0; FAILED=0

rm -f .t_bash_out .t_mini_out .t_valgrind_out .t_bash_err .t_mini_err

run_test() {
    local cmd="$1"
    local category="$2"
    
    TOTAL=$((TOTAL + 1))
    
    # Run in standard bash
    echo "$cmd" | $BASH_EXEC > .t_bash_out 2> .t_bash_err
    local bash_status=$?

    # Run in minishell with Valgrind and Timeout
    echo "$cmd" | $TIMEOUT $VALGRIND $MINISHELL > .t_mini_out 2> .t_valgrind_out
    local mini_status=$?

    # Check for timeout (exit code 124 usually means timeout)
    local timed_out=0
    if [ "$mini_status" -eq 124 ]; then timed_out=1; fi

    # Check Output (Stdout)
    local out_match=1
    if ! diff -q .t_bash_out .t_mini_out > /dev/null; then out_match=0; fi

    # Check Exit Status (Bash syntax errors return 2 or 258, map both as success if minishell returns either)
    local status_match=1
    if [ "$bash_status" -ne "$mini_status" ]; then
        if [[ ("$bash_status" -eq 2 || "$bash_status" -eq 258) && ("$mini_status" -eq 2 || "$mini_status" -eq 258) ]]; then
            status_match=1 # Treat as match for syntax errors
        else
            status_match=0
        fi
    fi

    # Check Memory & FD Leaks
    local mem_leak=0; local fd_leak=0
    if grep -q "definitely lost: [^0]" .t_valgrind_out || grep -q "Invalid read" .t_valgrind_out || grep -q "Invalid write" .t_valgrind_out; then
        mem_leak=1
    fi
    if grep -q "Open file descriptor [3-9]:" .t_valgrind_out || grep -q "Open file descriptor [1-9][0-9]:" .t_valgrind_out; then
        fd_leak=1
    fi

    # --- Print Results ---
    printf "${BLUE}[%s]${RESET} %-50s " "$category" "${cmd:0:45}"

    local test_failed=0

    if [ $timed_out -eq 1 ]; then
        printf "[${RED}HANG: KO (FD LEAK?)${RESET}]\n"
        test_failed=1
    else
        [ $out_match -eq 1 ] && printf "[${GREEN}OUT: OK${RESET}] " || { printf "[${RED}OUT: KO${RESET}] "; test_failed=1; }
        [ $status_match -eq 1 ] && printf "[${GREEN}RET: OK${RESET}] " || { printf "[${RED}RET: KO ($bash_status!=$mini_status)${RESET}] "; test_failed=1; }
        [ $mem_leak -eq 0 ] && printf "[${GREEN}MEM: OK${RESET}] " || { printf "[${RED}MEM: LEAK${RESET}] "; test_failed=1; }
        [ $fd_leak -eq 0 ] && printf "[${GREEN}FD: OK${RESET}]\n" || { printf "[${RED}FD: LEAK${RESET}]\n"; test_failed=1; }
    fi

    if [ $test_failed -eq 0 ]; then
        PASSED=$((PASSED + 1))
    else
        FAILED=$((FAILED + 1))
        [ $out_match -eq 0 ] && echo -e "   ${YELLOW}-> Expected out:${RESET} '$(cat .t_bash_out)'\n   ${YELLOW}-> Got out:     ${RESET} '$(cat .t_mini_out)'"
        if [ $mem_leak -eq 1 ] || [ $fd_leak -eq 1 ]; then
             echo -e "   ${YELLOW}-> Valgrind Log:${RESET}"; cat .t_valgrind_out | grep -E "lost:|Open file descriptor|Invalid" | sed 's/^/      /'
        fi
    fi
}

echo -e "======================================================"
echo -e "         MINISHELL V2: THE CLUSTER TORTURE TEST       "
echo -e "======================================================"

# --- 1. Syntax Errors & Crashes ---
run_test "| cat" "SYNTAX"
run_test "cat | | ls" "SYNTAX"
run_test ">" "SYNTAX"
run_test ">>" "SYNTAX"
run_test "<" "SYNTAX"
run_test "echo hello >" "SYNTAX"

# --- 2. The Expansion Torture ---
run_test "echo \$USER\$USER\$USER" "EXPAND"
run_test "echo \"\$?\"" "EXPAND"
run_test "echo '\$?'" "EXPAND"
run_test "echo \"'\$?'\"" "EXPAND"
run_test "export EMPTY=\"\" && cat \$EMPTY" "EXPAND"
run_test "echo \$DOES_NOT_EXIST" "EXPAND"
run_test "expr \$? + \$?" "EXPAND"

# --- 3. Path and Execution Edges ---
run_test "." "EXEC"
run_test ".." "EXEC"
run_test "./" "EXEC"
run_test "/bin/" "EXEC"
touch no_exec_file && chmod -x no_exec_file
run_test "./no_exec_file" "EXEC"
rm -f no_exec_file
run_test "export PATH=\"\" && ls" "EXEC"
run_test "unset PATH && ls" "EXEC"

# --- 4. Brutal Pipes & FD Handlers ---
# If FDs aren't closed, these WILL hang, and the timeout will catch it.
run_test "cat | cat | ls" "PIPES"
run_test "ls | wc | cat | grep 1 | cat | wc | cat" "PIPES"
run_test "grep a | grep b | grep c | grep d" "PIPES"

# --- 5. Redirection Edge Cases ---
export FILE="a b"
run_test "echo hello > \$FILE" "REDIR"
run_test "cat < /dev/urandom | head -n 1 | wc -l" "REDIR"
run_test "echo test > f1 > f2 > f3 && cat f3" "REDIR"
rm -f f1 f2 f3

# --- 6. Bonus Logic Traps ---
run_test "&&" "BONUS"
run_test "||" "BONUS"
run_test "echo a && && echo b" "BONUS"
run_test "( ( ls ) )" "BONUS"
run_test "(ls) | (wc -l)" "BONUS"
run_test "ls )" "BONUS"

rm -f .t_bash_out .t_mini_out .t_valgrind_out .t_bash_err .t_mini_err

echo -e "\n======================================================"
echo -e "Total Tests : $TOTAL | Passed: ${GREEN}$PASSED${RESET} | Failed: ${RED}$FAILED${RESET}"
echo -e "======================================================"
