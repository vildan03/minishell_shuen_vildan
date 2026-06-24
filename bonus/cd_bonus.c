/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:49:33 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 11:52:50 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor_bonus.h"
#include "minishell_bonus.h"
#include <errno.h>
#include <string.h>

static int	print_cd_error(char *target, char *msg)
{
	ft_putstr_fd("minishell: cd", 2);
	if (target)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(target, 2);
	}
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
	return (1);
}

static int	print_cd_errno(char *target)
{
	return (print_cd_error(target, strerror(errno)));
}

static char	*get_cd_target(char **args, t_shell *shell)
{
	char	*target;

	if (!shell || !shell->env)
		return (NULL);
	if (!args[1])
	{
		target = get_env_value_executor(shell->env, "HOME");
		if (!target)
			print_cd_error(NULL, "HOME not set");
		else if (*target == '\0')
			return (".");
		return (target);
	}
	if (ft_strncmp(args[1], "-", 2) == 0)
	{
		target = get_env_value_executor(shell->env, "OLDPWD");
		if (!target)
			print_cd_error(NULL, "OLDPWD not set");
		return (target);
	}
	return (args[1]);
}

static int	update_cd_state(t_shell *shell, char **args, char *old_pwd,
		char *new_pwd)
{
	if (old_pwd && update_env_value(shell, "OLDPWD", old_pwd) != 0)
		return (1);
	if (new_pwd && update_env_value(shell, "PWD", new_pwd) != 0)
		return (1);
	if (args[1] && ft_strncmp(args[1], "-", 2) == 0 && new_pwd)
	{
		if (write_builtin_str(new_pwd, "cd") != 0 || write_builtin_char('\n',
				"cd") != 0)
			return (1);
	}
	return (0);
}

int	exec_builtin_cd(char **args, t_shell *shell)
{
	char	*target;
	char	*old_pwd;
	char	*new_pwd;

	if (args[1] && args[2])
		return (print_cd_error(NULL, "too many arguments"), 2);
	target = get_cd_target(args, shell);
	if (!target)
		return (1);
	old_pwd = get_old_pwd(shell);
	new_pwd = perform_chdir(target, shell);
	if (!new_pwd)
		return (free(old_pwd), print_cd_errno(target));
	if (update_cd_state(shell, args, old_pwd, new_pwd) != 0)
		return (free(old_pwd), free(new_pwd), 1);
	return (free(old_pwd), free(new_pwd), 0);
}
