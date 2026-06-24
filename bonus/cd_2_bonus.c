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
			"cannot access parent directories: "
			"No such file or directory", 2);
		pwd_value = get_env_value_executor(shell->env, "PWD");
		if (pwd_value)
			old_pwd = ft_strdup(pwd_value);
	}
	return (old_pwd);
}

char	*build_logical_path(char **stack, int top)
{
	char	*res;
	char	*tmp;
	int		j;

	if (top == 0)
		return (ft_strdup("/"));
	res = ft_strdup("");
	j = 0;
	while (j < top)
	{
		tmp = ft_strjoin(res, "/");
		free(res);
		res = ft_strjoin(tmp, stack[j]);
		free(tmp);
		j++;
	}
	return (res);
}

static int	count_parts(char **parts)
{
	int	i;

	i = 0;
	while (parts[i])
		i++;
	return (i);
}

static char	*resolve_logical(char *pwd, char *target)
{
	char	*path;
	char	**parts;
	char	**stack;
	int		top;
	char	*res;

	if (!pwd || !target)
		return (NULL);
	path = get_initial_path(pwd, target);
	if (!path)
		return (NULL);
	parts = ft_split(path, '/');
	free(path);
	if (!parts)
		return (NULL);
	stack = malloc(sizeof(char *) * (count_parts(parts) + 1));
	if (!stack)
		return (free_split(parts), NULL);
	top = 0;
	process_path_parts(parts, stack, &top);
	res = build_logical_path(stack, top);
	free(stack);
	free_split(parts);
	return (res);
}

char	*get_new_pwd(char *target, t_shell *shell)
{
	char		*new_pwd;
	char		*pwd;
	char		*logical;
	struct stat	st_log;
	struct stat	st_dot;

	pwd = NULL;
	if (shell && shell->env)
		pwd = get_env_value_executor(shell->env, "PWD");
	logical = resolve_logical(pwd, target);
	if (logical && stat(logical, &st_log) == 0 && stat(".", &st_dot) == 0)
	{
		if (st_log.st_dev == st_dot.st_dev && st_log.st_ino == st_dot.st_ino)
			return (logical);
	}
	free(logical);
	new_pwd = getcwd(NULL, 0);
	if (new_pwd && ft_strcmp(target, "//") == 0 && ft_strcmp(new_pwd, "/") == 0)
	{
		free(new_pwd);
		new_pwd = ft_strdup("//");
	}
	return (new_pwd);
}
