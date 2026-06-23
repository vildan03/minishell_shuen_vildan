/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:53:15 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 17:46:19 by vikaradu         ###   ########.fr       */
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
		if (expanded_file && expanded_file[0] == 3 && expanded_file[1] == '\0')
			expanded_file[0] = '\0';
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

char	*expand_string(char *raw, char **env, int status)
{
	t_expand_ctx	ctx;
	int				has_quotes;

	ctx.raw = raw;
	ctx.env = env;
	ctx.status = status;
	ctx.i = 0;
	ctx.sq = 0;
	ctx.dq = 0;
	ctx.skip_inc = 0;
	ctx.res = ft_strdup("");
	if (!ctx.res)
		return (NULL);
	has_quotes = (ft_strchr(raw, '\'') != NULL || ft_strchr(raw, '"') != NULL);
	while (ctx.raw[ctx.i])
	{
		ctx.skip_inc = 0;
		ctx.res = process_expand_char(&ctx);
		if (!ctx.skip_inc)
			ctx.i++;
	}
	if (ctx.res && ctx.res[0] == '\0' && has_quotes)
		return (free(ctx.res), ft_strdup("\3"));
	return (ctx.res);
}
