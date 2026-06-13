
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

static int	command_error(char *cmd, char *msg, int status)
{
	print_cmd_error(cmd, msg);
	return (status);
}

int	validate_exec_path(char *cmd, char *path)
{
	if (!path)
		return (command_error(cmd, "command not found", 127));
	if (access(path, F_OK) != 0)
		return (command_error(cmd, "No such file or directory", 127));
	if (is_directory(path))
		return (command_error(path, "Is a directory", 126));
	if (access(path, X_OK) != 0)
		return (command_error(path, "Permission denied", 126));
	return (0);
}
