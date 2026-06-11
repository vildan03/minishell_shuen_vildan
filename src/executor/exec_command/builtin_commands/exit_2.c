#include "../../../../inc/executor.h"
#include "../../../../inc/minishell.h"

static void	exit_with_cleanup(t_shell *shell, int exit_code, int saved_stdout,
		int saved_stdin)
{
	if (saved_stdout != -1)
		close(saved_stdout);
	if (saved_stdin != -1)
		close(saved_stdin);
	cleanup_shell(shell);
	exit(exit_code);
}

int	exec_builtin_exit(char **args, t_shell *shell, int saved_stdout,
		int saved_stdin)
{
	int exit_code;
	long long parsed_value;

	if (isatty(STDIN_FILENO) && isatty(STDERR_FILENO))
		ft_putendl_fd("exit", 2);
	if (!args[1])
		exit_with_cleanup(shell, shell->last_exit_status, saved_stdout,
			saved_stdin);
	if (handle_exit_arg(args, shell, &parsed_value) != 0)
		return (1);
	exit_code = parsed_value % 256;
	if (exit_code < 0)
		exit_code += 256;
	exit_with_cleanup(shell, exit_code, saved_stdout, saved_stdin);
	return (0);
}
