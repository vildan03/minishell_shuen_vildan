
#include "../../../../inc/executor.h"
#include "../../../../inc/minishell.h"

static int	is_directory(char *path)
{
	struct stat	st;

	if (stat(path, &st) == -1)
		return (0);
	return (S_ISDIR(st.st_mode));
}
void	print_cmd_error(char *cmd, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
}
static void	exit_exec_error_2(char *path, t_shell *shell)
{
	if (is_directory(path))
	{
		print_cmd_error(path, "Is a directory");
		free(path);
		cleanup_shell(shell);
		exit(126);
	}
	if (access(path, X_OK) != 0)
	{
		print_cmd_error(path, "Permission denied");
		free(path);
		cleanup_shell(shell);
		exit(126);
	}
}

void	exit_exec_error(char *cmd, char *path, t_shell *shell)
{
	if (!path)
	{
		print_cmd_error(cmd, "command not found");
		cleanup_shell(shell);
		exit(127);
	}
	if (access(path, F_OK) != 0)
	{
		print_cmd_error(cmd, "No such file or directory");
		free(path);
		cleanup_shell(shell);
		exit(127);
	}
	exit_exec_error_2(path, shell);
}
