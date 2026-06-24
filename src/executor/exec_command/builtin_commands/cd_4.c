/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:01:00 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/24 14:01:00 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"

char	*resolve_logical(char *pwd, char *target);

char	*perform_chdir(char *target, t_shell *shell)
{
	char	*pwd;
	char	*logical;
	char	*new_pwd;

	pwd = NULL;
	if (shell && shell->env)
		pwd = get_env_value_executor(shell->env, "PWD");
	logical = resolve_logical(pwd, target);
	if (logical && chdir(logical) == 0)
		return (logical);
	if (chdir(target) != 0)
		return (free(logical), NULL);
	free(logical);
	new_pwd = getcwd(NULL, 0);
	if (new_pwd && ft_strcmp(target, "//") == 0 && ft_strcmp(new_pwd, "/") == 0)
		return (free(new_pwd), ft_strdup("//"));
	return (new_pwd);
}
