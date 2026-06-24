/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 10:49:30 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/24 10:49:30 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"

char	*get_initial_path(char *pwd, char *target)
{
	char	*path;
	char	*tmp;

	if (target[0] == '/')
		path = ft_strdup(target);
	else
	{
		tmp = ft_strjoin(pwd, "/");
		path = ft_strjoin(tmp, target);
		free(tmp);
	}
	return (path);
}

void	free_split(char **parts)
{
	int	i;

	i = 0;
	if (!parts)
		return ;
	while (parts[i])
	{
		free(parts[i]);
		i++;
	}
	free(parts);
}

void	process_path_parts(char **parts, char **stack, int *top)
{
	int	i;

	i = 0;
	while (parts[i])
	{
		if (ft_strcmp(parts[i], ".") == 0)
			;
		else if (ft_strcmp(parts[i], "..") == 0)
		{
			if (*top > 0)
				(*top)--;
		}
		else
			stack[(*top)++] = parts[i];
		i++;
	}
}
