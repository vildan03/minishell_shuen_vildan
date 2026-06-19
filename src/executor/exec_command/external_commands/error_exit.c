
#include "executor.h"
#include "minishell.h"
#include <errno.h>

static void	print_error_prefix(void)
{
	if (isatty(STDIN_FILENO) && isatty(STDERR_FILENO))
		ft_putstr_fd("minishell: ", 2);
	else
		ft_putstr_fd("minishell: line 1: ", 2);
}

static int	is_directory(char *path)
{
	struct stat	st;

	if (stat(path, &st) == -1)
		return (0);
	return (S_ISDIR(st.st_mode));
}

void	print_cmd_error(char *cmd, char *msg)
{
	print_error_prefix();
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
}

void	print_errno_error(char *cmd)
{
	print_cmd_error(cmd, strerror(errno));
}

int	validate_exec_path(char *cmd, char *path)
{
	if (!path)
		return (print_cmd_error(cmd, "command not found"), 127);
	if (access(path, F_OK) != 0)
		return (print_cmd_error(cmd, "No such file or directory"), 127);
	if (is_directory(path))
		return (print_cmd_error(path, "Is a directory"), 126);
	if (access(path, X_OK) != 0)
		return (print_cmd_error(path, "Permission denied"), 126);
	return (0);
}
