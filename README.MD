42 minishell project

normfmt is the alias to run norminette formatter
to run the leakcheck:
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --suppressions=readline.supp ./minishell