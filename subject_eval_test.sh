#!/bin/bash

MINISHELL="./minishell"
BASH_EXEC="bash"
VALGRIND_CMD=(
	valgrind
	--leak-check=full
	--show-leak-kinds=all
	--track-fds=yes
	--suppressions=readline.supp
	./minishell
)
TIMEOUT_CMD=(timeout 3s)
VALGRIND_TIMEOUT_CMD=(timeout 10s)

GREEN="\033[32m"
RED="\033[31m"
BLUE="\033[34m"
YELLOW="\033[33m"
RESET="\033[0m"

TOTAL=0
FAILED=0
PASSED=0
FAILURE_ID=0

TMPROOT="$(mktemp -d /tmp/minishell_subject_eval.XXXXXX)"
WORKDIR="$TMPROOT/work"
mkdir -p "$WORKDIR"

cleanup()
{
	rm -rf "$TMPROOT"
}

normalize_stderr()
{
	sed -E 's/^(bash|minishell)(: line [0-9]+)?: //'
}

has_fd_leak()
{
	awk '
		/^==[0-9]+== Open file descriptor / {
			getline next_line
			if (next_line !~ /<inherited from parent>/)
				bad = 1
		}
		END { exit bad }
	' "$1"
}

has_mem_issue()
{
	grep -Eq \
		'definitely lost: [1-9]|indirectly lost: [1-9]|possibly lost: [1-9]|still reachable: [1-9]|Invalid read|Invalid write' \
		"$1"
}

print_failure_details()
{
	printf "   ${YELLOW}failed command:${RESET}\n"
	sed -n '1,20p' "$WORKDIR/input.txt" | cat -A
	printf "   ${YELLOW}bash output:${RESET}\n"
	sed -n '1,20p' "$WORKDIR/bash_out.txt" | cat -A
	printf "   ${YELLOW}minishell output:${RESET}\n"
	sed -n '1,20p' "$WORKDIR/mini_out.txt" | cat -A
	printf "   ${YELLOW}bash stderr:${RESET}\n"
	sed -n '1,20p' "$WORKDIR/bash_err_norm.txt" | cat -A
	printf "   ${YELLOW}minishell stderr:${RESET}\n"
	sed -n '1,20p' "$WORKDIR/mini_err_norm.txt" | cat -A
	printf "   ${YELLOW}valgrind hints:${RESET}\n"
	grep -E 'lost:|Invalid|Open file descriptor' "$WORKDIR/vg_err.txt" \
		| sed -n '1,20p'
}

print_result_field()
{
	local	name="$1"
	local	status="$2"
	local	extra="$3"
	local	color="$GREEN"

	if [ "$status" = "KO" ]; then
		color="$RED"
	fi
	printf "[%s: %b%s%b" "$name" "$color" "$status" "$RESET"
	if [ -n "$extra" ]; then
		printf " %s" "$extra"
	fi
	printf "] "
}

print_progress()
{
	local	category="$1"
	local	label="$2"

	printf "\r${BLUE}Running test %d${RESET}: [%s] %s                    " \
		"$TOTAL" "$category" "$label"
}

run_case()
{
	local	label="$1"
	local	category="$2"
	local	append_exit="$3"
	local	input_file="$WORKDIR/input.txt"
	local	stdout_ok="OK"
	local	stderr_ok="OK"
	local	ret_ok="OK"
	local	mem_ok="OK"
	local	fd_ok="OK"
	local	timed_out="0"
	local	bash_status
	local	mini_status

	TOTAL=$((TOTAL + 1))
	print_progress "$category" "$label"
	cat > "$input_file"
	"${TIMEOUT_CMD[@]}" "$BASH_EXEC" < "$input_file" \
		> "$WORKDIR/bash_out.txt" 2> "$WORKDIR/bash_err.txt"
	bash_status=$?
	if [ "$append_exit" = "1" ]; then
		{
			cat "$input_file"
			printf 'exit\n'
		} | "${TIMEOUT_CMD[@]}" "$MINISHELL" > "$WORKDIR/mini_out.txt" \
			2> "$WORKDIR/mini_err.txt"
		mini_status=$?
		{
			cat "$input_file"
			printf 'exit\n'
		} | "${VALGRIND_TIMEOUT_CMD[@]}" "${VALGRIND_CMD[@]}" \
			> /dev/null 2> "$WORKDIR/vg_err.txt"
	else
		"${TIMEOUT_CMD[@]}" "$MINISHELL" < "$input_file" \
			> "$WORKDIR/mini_out.txt" 2> "$WORKDIR/mini_err.txt"
		mini_status=$?
		"${VALGRIND_TIMEOUT_CMD[@]}" "${VALGRIND_CMD[@]}" < "$input_file" \
			> /dev/null 2> "$WORKDIR/vg_err.txt"
	fi
	normalize_stderr < "$WORKDIR/bash_err.txt" > "$WORKDIR/bash_err_norm.txt"
	normalize_stderr < "$WORKDIR/mini_err.txt" > "$WORKDIR/mini_err_norm.txt"
	if [ "$bash_status" -eq 124 ] || [ "$mini_status" -eq 124 ]; then
		timed_out="1"
	fi
	diff -q "$WORKDIR/bash_out.txt" "$WORKDIR/mini_out.txt" >/dev/null \
		|| stdout_ok="KO"
	diff -q "$WORKDIR/bash_err_norm.txt" "$WORKDIR/mini_err_norm.txt" \
		>/dev/null || stderr_ok="KO"
	[ "$bash_status" -eq "$mini_status" ] || ret_ok="KO"
	has_mem_issue "$WORKDIR/vg_err.txt" && mem_ok="KO"
	has_fd_leak "$WORKDIR/vg_err.txt" || fd_ok="KO"
	if [ "$timed_out" = "1" ] || [ "$stdout_ok" = "KO" ] \
		|| [ "$stderr_ok" = "KO" ] || [ "$ret_ok" = "KO" ] \
		|| [ "$mem_ok" = "KO" ] || [ "$fd_ok" = "KO" ]; then
		FAILED=$((FAILED + 1))
		FAILURE_ID=$((FAILURE_ID + 1))
		printf "\n"
		printf "${RED}[ERROR%d]${RESET} ${BLUE}[%s]${RESET} %s " \
			"$FAILURE_ID" "$category" "$label"
		if [ "$timed_out" = "1" ]; then
			printf "[${RED}HANG${RESET}]\n"
		else
			print_result_field "OUT" "$stdout_ok" ""
			print_result_field "ERR" "$stderr_ok" ""
			if [ "$ret_ok" = "KO" ]; then
				print_result_field "RET" "$ret_ok" \
					"($bash_status!=$mini_status)"
			else
				print_result_field "RET" "$ret_ok" ""
			fi
			print_result_field "MEM" "$mem_ok" ""
			print_result_field "FD" "$fd_ok" ""
			printf "\n"
			if [ "$ret_ok" = "KO" ]; then
				printf "   ${YELLOW}exit code mismatch:${RESET} "
				printf "bash=%s minishell=%s\n" \
					"$bash_status" "$mini_status"
			fi
		fi
		print_failure_details
	else
		PASSED=$((PASSED + 1))
	fi
}

run_case_text()
{
	local	label="$1"
	local	category="$2"
	local	append_exit="$3"
	local	text="$4"

	run_case "$label" "$category" "$append_exit" <<EOF
$text
EOF
}

run_generated_subject_cases()
{
	local	word
	local	target
	local	cmd
	local	idx
	local	words=(
		alpha beta gamma delta epsilon
		one two three four five
		red blue green left right
		shell pipe quote
	)
	local	ls_targets=(
		README.md Makefile src
		bonus inc libft
		readline.supp subject_eval_test.sh minishell
	)
	local	status_cmds=(
		"/bin/true"
		"/bin/false"
		"/bin/echo ok"
		"/bin/ls README.md"
		"/bin/ls no_such_file"
		"pwd"
		"env | grep '^PATH='"
		"/bin/cat README.md"
		"/bin/cat no_such_file"
		"dsbksdgbksdghsd"
	)
	local	cd_cases=(
		$'cd '"$TMPROOT"$'\npwd'
		$'cd '"$TMPROOT/rel"$'\npwd'
		$'cd '"$TMPROOT/rel/sub"$'\npwd'
		$'cd '"$TMPROOT/rel/sub"$'\ncd ..\npwd'
		$'cd '"$TMPROOT/rel/sub"$'\ncd ../..\npwd'
		$'cd '"$TMPROOT"$'\ncd rel/sub\npwd'
		$'cd /tmp\npwd'
		$'cd /\npwd'
		$'cd '"$TMPROOT/rel/sub"$'\ncd .\npwd'
		$'cd '"$TMPROOT/rel/sub"$'\ncd ../../bin1\npwd'
	)
	local	rel_cases=(
		$'cd '"$TMPROOT/rel/sub"$'\n../hello_rel.sh'
		$'cd '"$TMPROOT/rel/sub"$'\n../../bin1/hello_path'
		$'cd '"$TMPROOT/rel/sub"$'\n../../bin2/hello_path'
		$'cd '"$TMPROOT"$'\n./rel/hello_rel.sh'
		$'cd '"$TMPROOT/rel"$'\n../bin1/hello_path'
		$'cd '"$TMPROOT/rel"$'\n./hello_rel.sh'
		$'cd '"$TMPROOT/rel/sub"$'\n../../bin1/hello_path\n../../bin2/hello_path'
		$'cd '"$TMPROOT"$'\n./bin1/hello_path'
	)
	local	path_cases=(
		$'export PATH='"$TMPROOT/bin1:$TMPROOT/bin2"$'\nhello_path'
		$'export PATH='"$TMPROOT/bin2:$TMPROOT/bin1"$'\nhello_path'
		$'export PATH=/bin:/usr/bin\nls README.md'
		$'export PATH=/usr/bin:/bin\nls README.md'
		$'export PATH='"$TMPROOT/bin1:/bin"$'\nhello_path'
		$'export PATH='"$TMPROOT/bin2:/bin"$'\nhello_path'
		$'unset PATH\n/bin/ls README.md'
		$'export PATH='"$TMPROOT/bin1:$TMPROOT/bin2"$'\nhello_path\necho $?'
	)
	local	pipe_words=(
		alpha beta gamma delta epsilon
		one two three four five
		red blue green left right
	)
	local	bonus_cases=(
		"/bin/true && echo ok"
		"/bin/false || echo ok"
		"/bin/false && echo no || echo yes"
		"(/bin/echo a) && (/bin/echo b)"
		"(/bin/echo a && /bin/echo b) | grep a"
		"(/bin/true || /bin/echo no) && echo yes"
		"(/bin/false || /bin/echo left) && /bin/echo right"
		"/bin/true && (/bin/echo inside)"
		"/bin/false || (/bin/echo inside)"
		"(/bin/echo alpha) | (cat)"
		"(/bin/echo alpha) && (/bin/echo beta)"
		"(/bin/false && /bin/echo no) || /bin/echo yes"
		"(/bin/true && /bin/echo ok) || /bin/echo no"
		"/bin/true && /bin/true && echo chain"
		"/bin/false || /bin/false || echo fallback"
	)

	idx=1
	for word in "${words[@]}"; do
		run_case_text "generated echo $idx" "MANDATORY" 1 "echo $word"
		run_case_text "generated echo -n $idx" "MANDATORY" 1 "echo -n $word"
		run_case_text "generated /bin/echo $idx" "MANDATORY" 1 \
			"/bin/echo $word $word"
		run_case_text "generated dq $idx" "MANDATORY" 1 \
			"echo \"$word $word\""
		run_case_text "generated sq $idx" "MANDATORY" 1 "echo '$word'"
		run_case_text "generated export $idx" "MANDATORY" 1 \
			"export LOOP_VAR=$word"$'\n''echo $LOOP_VAR'
		run_case_text "generated export dq $idx" "MANDATORY" 1 \
			"export LOOP_VAR=$word"$'\n''echo "$LOOP_VAR"'
		idx=$((idx + 1))
	done
	idx=1
	for target in "${ls_targets[@]}"; do
		run_case_text "generated ls abs $idx" "MANDATORY" 1 \
			"/bin/ls $target"
		run_case_text "generated ls rel $idx" "MANDATORY" 1 \
			"/bin/ls ./$target"
		idx=$((idx + 1))
	done
	idx=1
	for cmd in "${status_cmds[@]}"; do
		run_case_text "generated status $idx" "MANDATORY" 1 \
			"$cmd"$'\n''echo $?'
		idx=$((idx + 1))
	done
	idx=1
	for cmd in "${cd_cases[@]}"; do
		run_case_text "generated cd $idx" "MANDATORY" 1 "$cmd"
		idx=$((idx + 1))
	done
	idx=1
	for cmd in "${rel_cases[@]}"; do
		run_case_text "generated relative $idx" "MANDATORY" 1 "$cmd"
		idx=$((idx + 1))
	done
	idx=1
	for cmd in "${path_cases[@]}"; do
		run_case_text "generated path $idx" "MANDATORY" 1 "$cmd"
		idx=$((idx + 1))
	done
	idx=1
	for word in "${words[@]}"; do
		run_case_text "generated redir out $idx" "MANDATORY" 1 \
			"echo $word > $TMPROOT/gen_redir_$idx.txt"$'\n'"cat < $TMPROOT/gen_redir_$idx.txt"
		run_case_text "generated redir append $idx" "MANDATORY" 1 \
			"echo $word > $TMPROOT/gen_append_$idx.txt"$'\n'"echo $word >> $TMPROOT/gen_append_$idx.txt"$'\n'"cat $TMPROOT/gen_append_$idx.txt"
		idx=$((idx + 1))
	done
	idx=1
	for word in "${pipe_words[@]}"; do
		run_case_text "generated pipe cat $idx" "MANDATORY" 1 \
			"echo $word | cat"
		run_case_text "generated pipe wc $idx" "MANDATORY" 1 \
			"echo $word | wc -c"
		idx=$((idx + 1))
	done
	idx=1
	for cmd in "${bonus_cases[@]}"; do
		run_case_text "generated bonus $idx" "BONUS" 1 "$cmd"
		idx=$((idx + 1))
	done
}

setup_fixtures()
{
	mkdir -p "$TMPROOT/bin1" "$TMPROOT/bin2" "$TMPROOT/rel/sub" \
		"$TMPROOT/wildcards"
	printf '#!/bin/sh\necho LEFT\n' > "$TMPROOT/bin1/hello_path"
	printf '#!/bin/sh\necho RIGHT\n' > "$TMPROOT/bin2/hello_path"
	printf '#!/bin/sh\necho RELPATH_OK\n' > "$TMPROOT/rel/hello_rel.sh"
	printf 'alpha\nbeta\nbeta\n' > "$TMPROOT/pipe_src.txt"
	chmod +x "$TMPROOT/bin1/hello_path" "$TMPROOT/bin2/hello_path" \
		"$TMPROOT/rel/hello_rel.sh"
	touch "$TMPROOT/wildcards/0"
	touch "$TMPROOT/wildcards/Makefile"
	touch "$TMPROOT/wildcards/README.md"
	touch "$TMPROOT/wildcards/a b"
	touch "$TMPROOT/wildcards/bonus"
	touch "$TMPROOT/wildcards/cat"
	touch "$TMPROOT/wildcards/gemini_test.sh"
	touch "$TMPROOT/wildcards/gemini_test_2.sh"
	touch "$TMPROOT/wildcards/src"
}

trap cleanup EXIT

if [ ! -x "$MINISHELL" ]; then
	printf "${RED}Error:${RESET} %s not found or not executable.\n" \
		"$MINISHELL"
	exit 1
fi
if [ ! -f "readline.supp" ]; then
	printf "${RED}Error:${RESET} readline.supp not found.\n"
	exit 1
fi

setup_fixtures

printf "Manual-only checks not covered by this script: interactive ctrl-C / ctrl-D / ctrl-\\\\ signal behavior and history navigation.\n\n"

run_case "simple absolute command" "MANDATORY" 1 <<'EOF'
/bin/echo hi
EOF

run_case "empty command" "MANDATORY" 1 <<'EOF'

EOF

run_case "spaces only" "MANDATORY" 1 <<'EOF'
    
EOF

run_case "tabs only" "MANDATORY" 1 <<'EOF'
		
EOF

run_case "arguments without quotes" "MANDATORY" 1 <<'EOF'
/bin/ls README.md gemini_test.sh
EOF

run_case "more arguments" "MANDATORY" 1 <<'EOF'
/bin/echo alpha beta gamma
EOF

run_case "echo basics" "MANDATORY" 1 <<'EOF'
echo
echo hello world
echo ""
EOF

run_case "echo with -n" "MANDATORY" 1 <<'EOF'
echo -n -n hello
EOF

run_case "exit without argument" "MANDATORY" 0 <<'EOF'
exit
EOF

run_case "exit numeric" "MANDATORY" 0 <<'EOF'
exit 42
EOF

run_case "exit too many arguments" "MANDATORY" 1 <<'EOF'
exit 1 2
EOF

run_case "exit non numeric" "MANDATORY" 0 <<'EOF'
exit nope
EOF

run_case "return value and expr" "MANDATORY" 1 <<'EOF'
/bin/ls no_such_file
echo $?
expr $? + $?
EOF

run_case "return value success and fail" "MANDATORY" 1 <<'EOF'
/bin/true
echo $?
/bin/false
echo $?
EOF

run_case "double quotes" "MANDATORY" 1 <<'EOF'
echo "cat lol.c | cat > lol.c"
EOF

run_case "single quotes" "MANDATORY" 1 <<'EOF'
echo '$USER'
echo ''
EOF

run_case "environment variables" "MANDATORY" 1 <<'EOF'
export USER=tester
echo $USER
echo "$USER"
echo '$USER'
echo $DOES_NOT_EXIST
EOF

run_case "env" "MANDATORY" 1 <<'EOF'
env | grep '^PATH='
EOF

run_case "export and unset" "MANDATORY" 1 <<'EOF'
export TEST=123
env | grep '^TEST='
unset TEST
env | grep '^TEST='
echo $?
EOF

run_case "cd and pwd" "MANDATORY" 1 <<'EOF'
pwd
cd /tmp
pwd
cd -
pwd
EOF

run_case "cd dot dotdot and error" "MANDATORY" 1 <<EOF
cd $TMPROOT/rel/sub
cd .
pwd
cd ..
pwd
cd not_here
echo \$?
EOF

run_case "relative path" "MANDATORY" 1 <<EOF
cd $TMPROOT/rel/sub
../hello_rel.sh
EOF

run_case "complex relative path" "MANDATORY" 1 <<EOF
cd $TMPROOT/rel/sub
../../bin1/hello_path
EOF

run_case "PATH lookup order" "MANDATORY" 1 <<EOF
export PATH=$TMPROOT/bin1:$TMPROOT/bin2
hello_path
EOF

run_case "PATH lookup reverse order" "MANDATORY" 1 <<EOF
export PATH=$TMPROOT/bin2:$TMPROOT/bin1
hello_path
EOF

run_case "unset PATH" "MANDATORY" 1 <<'EOF'
unset PATH
ls
EOF

run_case "redirections" "MANDATORY" 1 <<EOF
echo test > $TMPROOT/out.txt
cat < $TMPROOT/out.txt
echo more >> $TMPROOT/out.txt
cat $TMPROOT/out.txt
EOF

run_case "redirection failures" "MANDATORY" 1 <<EOF
cat < $TMPROOT/no_such_input
echo one > $TMPROOT/first_out > $TMPROOT/second_out
cat $TMPROOT/second_out
EOF

run_case "heredoc" "MANDATORY" 1 <<'CASEEOF'
cat << EOF
hello
EOF
CASEEOF

run_case "pipes" "MANDATORY" 1 <<EOF
echo hi | cat | wc -c
/bin/ls README.md nofile | wc -l
ls | cat > $TMPROOT/pipe_out.txt
cat $TMPROOT/pipe_out.txt
EOF

run_case "more pipes" "MANDATORY" 1 <<EOF
cat $TMPROOT/pipe_src.txt | grep beta | wc -l
/bin/ls nofile | grep x | wc -l
cat $TMPROOT/pipe_src.txt | cat > $TMPROOT/pipe_copy.txt
cat $TMPROOT/pipe_copy.txt
EOF

run_case "invalid command" "MANDATORY" 1 <<'EOF'
dsbksdgbksdghsd
EOF

run_case "cat pipe chain" "MANDATORY" 1 <<'EOF'
cat | cat | ls
EOF

run_case "long command" "MANDATORY" 1 <<'EOF'
echo a b c d e f g h i j k l m n o p q r s t
EOF

run_case "bonus and/or" "BONUS" 1 <<'EOF'
true && echo success
false || echo fallback
false && echo skip || echo run
EOF

run_case "bonus parenthesis" "BONUS" 1 <<'EOF'
(echo a && echo b) | grep a
(ls) && (pwd)
EOF

run_case "bonus nested logic" "BONUS" 1 <<'EOF'
(false || echo ok) && echo done
true && (echo inside)
EOF

run_case "bonus wildcard" "BONUS" 1 <<EOF
cd $TMPROOT/wildcards
echo *
ls *
EOF

run_case "bonus surprise" "BONUS" 1 <<'EOF'
export USER=tester
echo "'$USER'"
echo '"$USER"'
EOF

run_generated_subject_cases

printf "\n======================================================\n"
printf "Total Tests : %d\n" "$TOTAL"
printf "Passed      : %b%d%b\n" "$GREEN" "$PASSED" "$RESET"
printf "Failed      : %b%d%b\n" "$RED" "$FAILED" "$RESET"
if [ "$TOTAL" -lt 300 ]; then
	printf "${RED}Warning:${RESET} total test count is below 300.\n"
fi
printf "======================================================\n"
