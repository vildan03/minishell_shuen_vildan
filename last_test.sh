#!/bin/bash

MINISHELL="./minishell"
BASH_EXEC="bash"
VALGRIND="valgrind --leak-check=full --track-fds=yes --errors-for-leak-kinds=all --quiet"
TIMEOUT="timeout 2s" # Catches pipe hangs

GREEN="\033[32m"; RED="\033[31m"; RESET="\033[0m"
TOTAL=0; FAILED=0

rm -f .fuzz_b_out .fuzz_m_out .fuzz_v_out .fuzz_b_err .fuzz_m_err

run_fuzz() {
    local cmd="$1"
    TOTAL=$((TOTAL + 1))
    
    # Run bash
    echo "$cmd" | $BASH_EXEC > .fuzz_b_out 2> .fuzz_b_err
    local b_stat=$?

    # Run minishell with valgrind and timeout
    echo "$cmd" | $TIMEOUT $VALGRIND $MINISHELL > .fuzz_m_out 2> .fuzz_v_out
    local m_stat=$?
    
    local is_timeout=0
    [ "$m_stat" -eq 124 ] && is_timeout=1

    local out_match=1
    if ! diff -q .fuzz_b_out .fuzz_m_out > /dev/null; then out_match=0; fi

    local stat_match=1
    if [ "$b_stat" -ne "$m_stat" ]; then
        if [[ ("$b_stat" -eq 2 || "$b_stat" -eq 258) && ("$m_stat" -eq 2 || "$m_stat" -eq 258) ]]; then
            stat_match=1 # Map syntax errors
        else
            stat_match=0
        fi
    fi

    local mem_leak=0; local fd_leak=0
    if grep -q "definitely lost:" .fuzz_v_out || grep -q "Invalid" .fuzz_v_out; then mem_leak=1; fi
    if grep -q "Open file descriptor [3-9]:" .fuzz_v_out || grep -q "Open file descriptor [1-9][0-9]:" .fuzz_v_out; then fd_leak=1; fi

    if [ $is_timeout -eq 1 ] || [ $out_match -eq 0 ] || [ $stat_match -eq 0 ] || [ $mem_leak -eq 1 ] || [ $fd_leak -eq 1 ]; then
        FAILED=$((FAILED + 1))
        echo -e "${RED}[FAIL]${RESET} Command: $cmd"
        [ $is_timeout -eq 1 ] && echo "       -> TIMEOUT (Likely FD Leak in pipes)"
        [ $out_match -eq 0 ] && echo "       -> Output mismatch"
        [ $stat_match -eq 0 ] && echo "       -> Exit code mismatch (Bash: $b_stat, Mini: $m_stat)"
        [ $mem_leak -eq 1 ] && echo "       -> Memory Leak detected"
        [ $fd_leak -eq 1 ] && echo "       -> FD Leak detected"
    fi
}

echo "Starting Fuzzer... (This will run hundreds of tests)"

# --- 1. The Syntax Error Fuzzer (Tests parser robustness) ---
# Evaluators will try to crash your parser with random tokens
TOKENS=("|" "<" ">" ">>" "<<" "&&" "||" "(" ")" '""' "''" "$?")
for t1 in "${TOKENS[@]}"; do
    for t2 in "${TOKENS[@]}"; do
        run_fuzz "$t1 $t2"
        run_fuzz "ls $t1 $t2 cat"
    done
done

# --- 2. The Expansion Fuzzer (Tests variable leaks and segfaults) ---
VARS=("" "\$USER" "\$?" "\$DOES_NOT_EXIST" "\$USER\$USER" "\"\$USER\"" "'\$USER'" "  \$USER  ")
for v1 in "${VARS[@]}"; do
    for v2 in "${VARS[@]}"; do
        run_fuzz "echo $v1 $v2"
        run_fuzz "cat $v1"
    done
done

# --- 3. The FD Exhaustion Pipeline (Tests if pipes close properly) ---
# If you don't close FDs in the parent process, a large pipe chain will freeze or crash.
run_fuzz "ls | cat | wc | cat | cat | cat | cat | cat | cat | cat | grep a | cat | wc"
run_fuzz "cat /dev/urandom | head -n 100 | cat | grep a | wc -l"

# --- 4. Deep Directory & Path Testing ---
run_fuzz "export PATH=\"\" && ls"
run_fuzz "unset PATH && /bin/ls"
run_fuzz "cd .. && cd .. && cd .. && pwd"
run_fuzz "cd .."
run_fuzz "cd ."

# --- 5. Redirection Edge Cases ---
run_fuzz "echo a > out1 > out2 > out3 && cat out3"
run_fuzz "< Makefile cat > out1 | grep a > out2"
run_fuzz "cat < does_not_exist | grep a"
rm -f out1 out2 out3

echo "Fuzzing complete. Total: $TOTAL | Failed: $FAILED"