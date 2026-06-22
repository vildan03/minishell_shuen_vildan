/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:50:01 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 10:50:02 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor_bonus.h"
#include "minishell_bonus.h"

static int	find_matching_key(char *env_line, char *key)
{
	int	i;

	i = 0;
	while (key[i] && env_line[i] && env_line[i] == key[i])
		i++;
	if (key[i] == '\0' && (env_line[i] == '=' || env_line[i] == '\0'))
		return (1);
	return (0);
}

static void	remove_env_index(char **arr, int index)
{
	free(arr[index]);
	while (arr[index + 1])
	{
		arr[index] = arr[index + 1];
		index++;
	}
	arr[index] = NULL;
}

static void	remove_from_array(char **arr, char *key)
{
	int	i;

	if (!arr || !key)
		return ;
	i = 0;
	while (arr[i])
	{
		if (find_matching_key(arr[i], key))
		{
			remove_env_index(arr, i);
			return ;
		}
		i++;
	}
}

int	exec_builtin_unset(char **args, t_shell *shell)
{
	int	i;

	if (!shell)
		return (1);
	i = 1;
	while (args[i])
	{
		remove_from_array(shell->env, args[i]);
		remove_from_array(shell->export, args[i]);
		i++;
	}
	return (0);
}
