/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_4_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:01:00 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/24 14:01:00 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor_bonus.h"
#include "minishell_bonus.h"

char	*resolve_logical(char *pwd, char *target);

static int	logical_matches_dot(char *logical)
{
	struct stat	st_log;
	struct stat	st_dot;

	if (!logical)
		return (0);
	if (stat(logical, &st_log) != 0 || stat(".", &st_dot) != 0)
		return (0);
	return (st_log.st_dev == st_dot.st_dev
		&& st_log.st_ino == st_dot.st_ino);
}

char	*get_new_pwd(char *target, t_shell *shell)
{
	char	*new_pwd;
	char	*pwd;
	char	*logical;

	pwd = NULL;
	if (shell && shell->env)
		pwd = get_env_value_executor(shell->env, "PWD");
	logical = resolve_logical(pwd, target);
	if (logical && logical_matches_dot(logical))
		return (logical);
	free(logical);
	new_pwd = getcwd(NULL, 0);
	if (new_pwd && ft_strcmp(target, "//") == 0 && ft_strcmp(new_pwd, "/") == 0)
		return (free(new_pwd), ft_strdup("//"));
	return (new_pwd);
}
