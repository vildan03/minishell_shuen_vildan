/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:53:17 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 10:53:18 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander_bonus.h"
#include "minishell_bonus.h"

int	is_env_char(char c)
{
	if (ft_isalnum(c) == 1)
		return (1);
	else if (c == '_')
		return (1);
	else if (c == '?')
		return (1);
	else
		return (0);
}

char	*append_char(char *str, char c)
{
	char	*new_str;
	int		len;
	int		i;

	len = 0;
	if (str)
		len = ft_strlen(str);
	new_str = malloc(len + 2);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	new_str[i + 1] = '\0';
	free(str);
	return (new_str);
}

char	*append_string(char *str, char *append)
{
	char	*new_str;

	if (!str || !append)
		return (str);
	new_str = ft_strjoin(str, append);
	free(str);
	return (new_str);
}

char	*get_env_value(char **env, char *key)
{
	int	i;
	int	len;

	if (!env || !key)
		return ("");
	i = 0;
	len = ft_strlen(key);
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], key, len) == 0 && env[i][len] == '=')
			return (env[i] + len + 1);
		i++;
	}
	return ("");
}
