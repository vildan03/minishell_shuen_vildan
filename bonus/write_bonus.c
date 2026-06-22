/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:50:08 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 10:50:09 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor_bonus.h"
#include "minishell_bonus.h"
#include <errno.h>
#include <string.h>

int	print_env_error(char *arg)
{
	ft_putstr_fd("minishell: env: '", 2);
	ft_putstr_fd(arg, 2);
	ft_putendl_fd("': No such file or directory", 2);
	return (127);
}

int	print_write_error(char *name)
{
	if (errno == EPIPE)
		return (1);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": write error: ", 2);
	ft_putendl_fd(strerror(errno), 2);
	return (1);
}

int	write_builtin_char(char c, char *name)
{
	if (write(STDOUT_FILENO, &c, 1) == -1)
		return (print_write_error(name));
	return (0);
}

int	write_builtin_str(char *str, char *name)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (write(STDOUT_FILENO, &str[i], 1) == -1)
			return (print_write_error(name));
		i++;
	}
	return (0);
}

int	write_export_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (write(STDOUT_FILENO, &str[i], 1) == -1)
			return (print_write_error("export"));
		i++;
	}
	return (0);
}
