/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:51:23 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 10:51:24 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor_bonus.h"
#include "minishell_bonus.h"
#include <errno.h>

static char	*print_error_prefix(void)
{
	if (isatty(STDIN_FILENO) && isatty(STDERR_FILENO))
		return ("minishell: ");
	return ("minishell: line 1: ");
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
	char	*prefix;
	size_t	len;
	char	*line;
	int		unused;

	prefix = print_error_prefix();
	len = ft_strlen(prefix) + ft_strlen(cmd) + ft_strlen(msg) + 4;
	line = malloc(len);
	if (!line)
		return ;
	ft_strlcpy(line, prefix, len);
	ft_strlcat(line, cmd, len);
	ft_strlcat(line, ": ", len);
	ft_strlcat(line, msg, len);
	ft_strlcat(line, "\n", len);
	unused = write(2, line, ft_strlen(line));
	(void)unused;
	free(line);
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
