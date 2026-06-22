/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:53:20 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 13:17:55 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static char	*process_expand_char(t_expand_ctx *ctx)
{
	if ((ctx->raw[ctx->i] == '\'' && !ctx->dq) || (ctx->raw[ctx->i] == '"'
			&& !ctx->sq))
		toggle_quotes(ctx->raw[ctx->i], &ctx->sq, &ctx->dq);
	else if (ctx->raw[ctx->i] == '$' && (ctx->raw[ctx->i + 1] == '"'
			|| ctx->raw[ctx->i + 1] == '\'') && !ctx->sq && !ctx->dq
		&& (ctx->i == 0 || ctx->raw[ctx->i - 1] != '$'))
		ctx->i++;
	else
		ctx->res = expand_string_2(ctx);
	return (ctx->res);
}

char	*expand_string(char *raw, char **env, int status)
{
	t_expand_ctx	ctx;

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
	while (ctx.raw[ctx.i])
	{
		ctx.skip_inc = 0;
		ctx.res = process_expand_char(&ctx);
		if (!ctx.skip_inc)
			ctx.i++;
	}
	return (ctx.res);
}

static void	expand_command_args_2(t_ast_node *node, char **env, int last_status,
		char **new_args)
{
	expand_wildcards(node);
	expand_redirections(node->redir, env, last_status);
	new_args = malloc(sizeof(char *) * (count_valid_args(node->args) + 1));
	if (!new_args)
		return ;
	filter_empty_args(node, new_args);
	unmask_args(new_args);
}

void	expand_command_args(t_ast_node *node, char **env, int last_status)
{
	int		i;
	char	*raw;
	char	*expanded;

	if (!node || !node->args)
		return ;
	i = -1;
	while (node->args[++i] != NULL)
	{
		raw = node->args[i];
		expanded = expand_string(raw, env, last_status);
		if (!expanded)
			return ;
		free(raw);
		node->args[i] = expanded;
	}
	expand_command_args_2(node, env, last_status, NULL);
}
