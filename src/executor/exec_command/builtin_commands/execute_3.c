/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:49:42 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 10:49:43 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"

static char	*get_pwd_cwd(t_shell *shell)
{
	char	*cwd;
	char	*pwd;

	cwd = getcwd(NULL, 0);
	if (!cwd && shell && shell->env)
	{
		pwd = get_env_value_executor(shell->env, "PWD");
		if (pwd)
			cwd = ft_strdup(pwd);
	}
	if (cwd && shell && shell->env)
	{
		pwd = get_env_value_executor(shell->env, "PWD");
		if (pwd && ft_strcmp(cwd, "/") == 0 && ft_strcmp(pwd, "//") == 0)
		{
			free(cwd);
			cwd = ft_strdup("//");
		}
	}
	return (cwd);
}

int	exec_builtin_pwd(t_shell *shell)
{
	char	*cwd;

	cwd = get_pwd_cwd(shell);
	if (!cwd)
		return (1);
	if (write_builtin_str(cwd, "pwd") != 0 || write_builtin_char('\n',
			"pwd") != 0)
		return (free(cwd), 1);
	free(cwd);
	return (0);
}
