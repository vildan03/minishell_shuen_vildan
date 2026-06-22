/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:53:15 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 10:53:16 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void	toggle_quotes(char c, int *sq, int *dq)
{
	if (c == '\'' && !(*dq))
		*sq = !(*sq);
	else if (c == '"' && !(*sq))
		*dq = !(*dq);
}

static char	*strip_heredoc_quotes(char *raw)
{
	char	*clean;
	int		i;
	int		j;

	clean = malloc(ft_strlen(raw) + 1);
	if (!clean)
		return (NULL);
	i = 0;
	j = 0;
	while (raw[i])
	{
		if (raw[i] == '$' && raw[i + 1] == '"' && (i == 0 || raw[i - 1] != '$'))
		{
			i++;
			continue ;
		}
		if (raw[i] != '\'' && raw[i] != '"')
			clean[j++] = raw[i];
		i++;
	}
	clean[j] = '\0';
	return (clean);
}

void	expand_redirections(t_redir *redir_list, char **env, int status)
{
	t_redir	*current;
	char	*expanded_file;

	current = redir_list;
	while (current != NULL)
	{
		if (current->type == REDIR_HEREDOC)
			expanded_file = strip_heredoc_quotes(current->file);
		else
			expanded_file = expand_string(current->file, env, status);
		free(current->file);
		current->file = expanded_file;
		current = current->next;
	}
}

int	count_valid_args(char **args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (args[i] != NULL)
	{
		if (args[i][0] != '\0')
			count++;
		i++;
	}
	return (count);
}
