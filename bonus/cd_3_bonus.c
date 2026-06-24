/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_3_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:01:00 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/24 14:01:00 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor_bonus.h"
#include "minishell_bonus.h"

static void	free_split(char **parts)
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

static char	**build_logical_stack(char **parts, int *top)
{
	char	**stack;
	int		i;

	i = 0;
	while (parts[i])
		i++;
	stack = malloc(sizeof(char *) * (i + 1));
	if (!stack)
		return (NULL);
	i = 0;
	*top = 0;
	while (parts[i])
	{
		if (ft_strcmp(parts[i], ".") == 0)
			;
		else if (ft_strcmp(parts[i], "..") == 0 && *top > 0)
			(*top)--;
		else if (ft_strcmp(parts[i], "..") != 0)
			stack[(*top)++] = parts[i];
		i++;
	}
	return (stack);
}

static char	*build_logical_path(char **stack, int top)
{
	char	*res;
	char	*tmp;
	int		i;

	if (top == 0)
		return (ft_strdup("/"));
	res = ft_strdup("");
	i = 0;
	while (i < top)
	{
		tmp = ft_strjoin(res, "/");
		free(res);
		res = ft_strjoin(tmp, stack[i]);
		free(tmp);
		i++;
	}
	return (res);
}

static char	*join_target_path(char *pwd, char *target)
{
	char	*path;
	char	*tmp;

	if (target[0] == '/')
		return (ft_strdup(target));
	tmp = ft_strjoin(pwd, "/");
	if (!tmp)
		return (NULL);
	path = ft_strjoin(tmp, target);
	free(tmp);
	return (path);
}

char	*resolve_logical(char *pwd, char *target)
{
	char	*path;
	char	**parts;
	char	**stack;
	char	*res;
	int		top;

	if (!pwd || !target)
		return (NULL);
	path = join_target_path(pwd, target);
	if (!path)
		return (NULL);
	parts = ft_split(path, '/');
	free(path);
	if (!parts)
		return (NULL);
	stack = build_logical_stack(parts, &top);
	if (!stack)
		return (free_split(parts), NULL);
	res = build_logical_path(stack, top);
	return (free(stack), free_split(parts), res);
}
