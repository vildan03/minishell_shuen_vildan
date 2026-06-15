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

static int	restore_exit_fds(int saved_stdout, int saved_stdin, int status)
{
	if (dup2(saved_stdout, STDOUT_FILENO) == -1)
		status = 1;
	if (dup2(saved_stdin, STDIN_FILENO) == -1)
		status = 1;
	close(saved_stdout);
	close(saved_stdin);
	return (status);
}

int	exec_builtin_exit(char **args, t_shell *shell, int saved_stdout,
		int saved_stdin)
{
	int			arg_status;
	int			exit_code;
	long long	parsed_value;

	if (isatty(STDIN_FILENO) && isatty(STDERR_FILENO))
		ft_putendl_fd("exit", 2);
	if (!args[1])
		exit_with_cleanup(shell, shell->last_exit_status, saved_stdout,
			saved_stdin);
	arg_status = handle_exit_arg(args, shell, &parsed_value);
	if (arg_status == 1)
		return (restore_exit_fds(saved_stdout, saved_stdin, 1));
	if (arg_status == 2)
		exit_with_cleanup(shell, 2, saved_stdout, saved_stdin);
	exit_code = parsed_value % 256;
	if (exit_code < 0)
		exit_code += 256;
	exit_with_cleanup(shell, exit_code, saved_stdout, saved_stdin);
	return (0);
}
