/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:49:59 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 11:55:50 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor_bonus.h"
#include "minishell_bonus.h"

static char	*create_export_entry(char *key, char *value)
{
	char	*tmp;
	char	*entry;

	if (!value)
		return (ft_strdup(key));
	tmp = ft_strjoin(key, "=");
	if (!tmp)
		return (NULL);
	entry = ft_strjoin(tmp, value);
	free(tmp);
	return (entry);
}

static int	replace_export_value(t_shell *shell, char *key, char *value)
{
	int		i;
	int		key_len;
	char	*entry;

	i = 0;
	key_len = ft_strlen(key);
	while (shell->export[i])
	{
		if (ft_strncmp(shell->export[i], key, key_len) == 0
			&& (shell->export[i][key_len] == '='
			|| shell->export[i][key_len] == '\0'))
		{
			if (!value)
				return (0);
			entry = create_export_entry(key, value);
			if (!entry)
				return (1);
			free(shell->export[i]);
			shell->export[i] = entry;
			return (0);
		}
		i++;
	}
	return (1);
}

static int	add_export_value(t_shell *shell, char *key, char *value)
{
	char	**new_export;
	char	*entry;
	int		len;

	len = 0;
	while (shell->export[len])
		len++;
	entry = create_export_entry(key, value);
	if (!entry)
		return (1);
	new_export = malloc(sizeof(char *) * (len + 2));
	if (!new_export)
		return (free(entry), 1);
	len = -1;
	while (shell->export[++len])
		new_export[len] = shell->export[len];
	new_export[len++] = entry;
	new_export[len] = NULL;
	free(shell->export);
	shell->export = new_export;
	return (0);
}

int	update_export_value(t_shell *shell, char *key, char *value)
{
	if (!shell || !shell->export || !key)
		return (1);
	if (replace_export_value(shell, key, value) == 0)
		return (0);
	return (add_export_value(shell, key, value));
}

int	print_export(t_shell *shell)
{
	int	i;

	if (!shell || !shell->export)
		return (1);
	sort_export(shell->export);
	i = 0;
	while (shell->export[i])
	{
		if (print_export_line(shell->export[i]) != 0)
			return (shell->last_exit_status = 1, 1);
		i++;
	}
	return (0);
}
