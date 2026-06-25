#!/bin/bash

# --- Configuration ---
MINISHELL="./minishell"
BASH_EXEC="bash" # Using standard bash, not posix
VALGRIND="valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --errors-for-leak-kinds=all --quiet"

# --- Colors ---
GREEN="\033[32m"
RED="\033[31m"
YELLOW="\033[33m"
BLUE="\033[34m"
RESET="\033[0m"

# --- Counters ---
TOTAL=0
PASSED=0
FAILED=0

# --- Cleanup ---
rm -f .test_bash_out .test_mini_out .test_valgrind_out .test_bash_err .test_mini_err

# --- Testing Function ---
run_test() {
    local cmd="$1"
    local category="$2"
    
    TOTAL=$((TOTAL + 1))
    
    # Run in standard bash
    echo "$cmd" | $BASH_EXEC > .test_bash_out 2> .test_bash_err
    local bash_status=$?

    # Run in minishell with Valgrind
    echo "$cmd" | $VALGRIND $MINISHELL > .test_mini_out 2> .test_valgrind_out
    local mini_status=$?

    # Check Output (Stdout)
    local out_match=1
    if ! diff -q .test_bash_out .test_mini_out > /dev/null; then
        out_match=0
    fi

    # Check Exit Status
    local status_match=1
    if [ "$bash_status" -ne "$mini_status" ]; then
        status_match=0
    fi

    # Check Memory Leaks
    local mem_leak=0
    if grep -q "definitely lost: [^0]" .test_valgrind_out || grep -q "indirectly lost: [^0]" .test_valgrind_out || grep -q "Invalid read" .test_valgrind_out || grep -q "Invalid write" .test_valgrind_out; then
        mem_leak=1
    fi

    # Check FD Leaks
    local fd_leak=0
    # Valgrind usually reports 3 or 4 open FDs at exit (0, 1, 2, and sometimes the log file itself). 
    # We grep for specific "Open file descriptor" warnings that aren't std fds.
    if grep -q "Open file descriptor [3-9]:" .test_valgrind_out || grep -q "Open file descriptor [1-9][0-9]:" .test_valgrind_out; then
        fd_leak=1
    fi

    # --- Print Results ---
    printf "${BLUE}[%s]${RESET} %-45s " "$category" "$cmd"

    local test_failed=0

    # Output matches?
    if [ $out_match -eq 1 ]; then
        printf "[${GREEN}OUT: OK${RESET}] "
    else
        printf "[${RED}OUT: KO${RESET}] "
        test_failed=1
    fi

    # Status matches?
    if [ $status_match -eq 1 ]; then
        printf "[${GREEN}RET: OK${RESET}] "
    else
        printf "[${RED}RET: KO (${bash_status}!=${mini_status})${RESET}] "
        test_failed=1
    fi

    # Memory leaks?
    if [ $mem_leak -eq 0 ]; then
        printf "[${GREEN}MEM: OK${RESET}] "
    else
        printf "[${RED}MEM: LEAK${RESET}] "
        test_failed=1
    fi

    # FD leaks?
    if [ $fd_leak -eq 0 ]; then
        printf "[${GREEN}FD: OK${RESET}]\n"
    else
        printf "[${RED}FD: LEAK${RESET}]\n"
        test_failed=1
    fi

    if [ $test_failed -eq 0 ]; then
        PASSED=$((PASSED + 1))
    else
        FAILED=$((FAILED + 1))
        echo -e "   ${YELLOW}-> Expected out:${RESET} '$(cat .test_bash_out)'"
        echo -e "   ${YELLOW}-> Got out:     ${RESET} '$(cat .test_mini_out)'"
        if [ $mem_leak -eq 1 ] || [ $fd_leak -eq 1 ]; then
             echo -e "   ${YELLOW}-> Valgrind Log:${RESET}"
             cat .test_valgrind_out | sed 's/^/      /'
        fi
    fi
}

echo -e "======================================================"
echo -e "               MINISHELL INTENSIVE TESTER             "
echo -e "======================================================"

if [ ! -f "$MINISHELL" ]; then
    echo -e "${RED}Error: Executable '$MINISHELL' not found.${RESET}"
    exit 1
fi

# --- 1. Simple Commands & Absolute Paths ---
run_test "ls" "SIMPLE"
run_test "/bin/ls" "SIMPLE"
run_test "    ls    -l   " "SIMPLE"
run_test "pwd" "SIMPLE"
run_test "" "EMPTY"
run_test "    " "EMPTY"

# --- 2. Quotes ---
run_test "echo 'hello world'" "QUOTES"
run_test "echo \"hello world\"" "QUOTES"
run_test "echo '\"hello\"'" "QUOTES"
run_test "echo \"'hello'\"" "QUOTES"
run_test "echo ''" "QUOTES"
run_test "echo \"\"" "QUOTES"

# --- 3. Environment Variables & Expansion ---
run_test "echo \$USER" "ENV"
run_test "echo \"\$USER\"" "ENV"
run_test "echo '\$USER'" "ENV"
run_test "echo \$NON_EXISTENT_VAR" "ENV"
run_test "echo \"hello \$USER\"" "ENV"
run_test "echo \$? \$?" "ENV"

# --- 4. Builtins ---
run_test "cd /tmp && pwd" "BUILTIN"
run_test "cd .. && pwd" "BUILTIN"
run_test "export TEST=123 && env | grep TEST" "BUILTIN"
run_test "export TEST=123 && unset TEST && env | grep TEST" "BUILTIN"
run_test "echo -n hello" "BUILTIN"
run_test "echo -n -n -n hello" "BUILTIN"
run_test "exit 42" "BUILTIN"

# --- 5. Redirections ---
run_test "echo 'test' > out1 && cat out1" "REDIR"
run_test "echo 'test2' > out1 && cat < out1" "REDIR"
run_test "ls > out2 > out3 > out4 && ls out*" "REDIR"
run_test "cat < does_not_exist" "REDIR"
rm -f out1 out2 out3 out4

# --- 6. Pipes ---
run_test "ls | wc -l" "PIPES"
run_test "cat Makefile | grep NAME | wc -l" "PIPES"
run_test "ls | grep a | wc -w" "PIPES"
run_test "ls does_not_exist | wc -l" "PIPES"

# --- 7. Mixed & Complex ---
run_test "echo 'hello' > out_mix | cat out_mix" "MIXED"
run_test "ls | cat -e > out_mix && cat out_mix | grep M" "MIXED"
rm -f out_mix

# --- 8. Bonus Features ---
run_test "true && echo 'success'" "BONUS"
run_test "false || echo 'fallback'" "BONUS"
run_test "false && echo 'skip' || echo 'run'" "BONUS"
run_test "(echo a && echo b) | grep a" "BONUS"
run_test "(ls) && (pwd)" "BONUS"
run_test "ls *" "BONUS"

# --- Cleanup & Summary ---
rm -f .test_bash_out .test_mini_out .test_valgrind_out .test_bash_err .test_mini_err out*

echo -e "\n======================================================"
echo -e "                     RESULTS SUMARY                   "
echo -e "======================================================"
echo -e "Total Tests : $TOTAL"
echo -e "Passed      : ${GREEN}$PASSED${RESET}"
echo -e "Failed      : ${RED}$FAILED${RESET}"

if [ "$FAILED" -eq 0 ]; then
    echo -e "\n${GREEN}Perfect score! Your minishell is solid.${RESET}"
else
    echo -e "\n${RED}Some tests failed. Check the logs above.${RESET}"
fi
