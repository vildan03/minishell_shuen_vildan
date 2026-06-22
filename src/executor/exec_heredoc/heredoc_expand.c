/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:52:02 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 13:17:34 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/executor.h"
#include "../../../inc/expander.h"

int	process_heredoc(t_redir *redir, t_shell *shell)
{
	if (!redir || redir->type != REDIR_HEREDOC)
		return (-1);
	return (create_heredoc_fd(redir, shell));
}

static char	*expand_heredoc_var(t_hd_expand *ctx)
{
	int		start;
	char	*key;
	char	*value;

	ctx->i++;
	if (ctx->line[ctx->i] == '?')
		return (ctx->i++, ft_itoa(ctx->status));
	start = ctx->i;
	while (ctx->line[ctx->i] && (ft_isalnum(ctx->line[ctx->i])
			|| ctx->line[ctx->i] == '_'))
		ctx->i++;
	key = ft_substr(ctx->line, start, ctx->i - start);
	value = ft_strdup(get_env_value(ctx->env, key));
	free(key);
	return (value);
}

static char	*expand_heredoc_line_2(char *expanded, t_hd_expand *ctx)
{
	char	*value;

	value = expand_heredoc_var(ctx);
	if (!value)
		return (free(expanded), NULL);
	expanded = append_string(expanded, value);
	free(value);
	return (expanded);
}

static char	*append_substring(char *str, char *line, int start, int len)
{
	char	*sub;
	char	*new_str;

	sub = ft_substr(line, start, len);
	if (!sub)
		return (NULL);
	new_str = append_string(str, sub);
	free(sub);
	return (new_str);
}

char	*expand_heredoc_line(char *line, char **env, int status)
{
	int			start;
	char		*expanded;
	t_hd_expand	ctx;

	ctx.line = line;
	ctx.env = env;
	ctx.status = status;
	ctx.i = 0;
	expanded = ft_strdup("");
	if (!expanded)
		return (NULL);
	while (ctx.line[ctx.i])
	{
		start = ctx.i;
		while (ctx.line[ctx.i] && !(ctx.line[ctx.i] == '$'
				&& is_env_char(ctx.line[ctx.i + 1])))
			ctx.i++;
		if (ctx.i > start)
			expanded = append_substring(expanded, ctx.line, start, ctx.i
					- start);
		if (ctx.line[ctx.i] == '$' && is_env_char(ctx.line[ctx.i + 1]))
			expanded = expand_heredoc_line_2(expanded, &ctx);
		if (!expanded)
			return (NULL);
	}
	return (expanded);
}
