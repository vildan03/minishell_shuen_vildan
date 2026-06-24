/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_2_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:49:30 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/24 12:26:24 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor_bonus.h"
#include "minishell_bonus.h"

char	*get_old_pwd(t_shell *shell)
{
	char	*old_pwd;
	char	*pwd_value;

	old_pwd = getcwd(NULL, 0);
	if (!old_pwd && shell && shell->env)
	{
		ft_putendl_fd("cd: error retrieving current directory: getcwd: "
			"cannot access parent directories:
			 No such file or directory", 2);
		pwd_value = get_env_value_executor(shell->env, "PWD");
		if (pwd_value)
			old_pwd = ft_strdup(pwd_value);
	}
	return (old_pwd);
}

char	*get_new_pwd(char *target)
{
	char	*new_pwd;

	new_pwd = getcwd(NULL, 0);
	if (new_pwd && ft_strcmp(target, "//") == 0 && ft_strcmp(new_pwd, "/") == 0)
	{
		free(new_pwd);
		new_pwd = ft_strdup("//");
	}
	return (new_pwd);
}
