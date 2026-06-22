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

static int	count_split_args(char **args)
{
	int		i;
	int		count;
	char	**split;
	int		j;

	i = 0;
	count = 0;
	while (args && args[i])
	{
		split = ft_split(args[i], 2);
		j = 0;
		while (split && split[j])
		{
			free(split[j]);
			count++;
			j++;
		}
		free(split);
		i++;
	}
	return (count);
}

static char	**split_all_args(char **args)
{
	char	**new_args;
	char	**split;
	int		i;
	int		j;
	int		k;

	new_args = malloc(sizeof(char *) * (count_split_args(args) + 1));
	if (!new_args)
		return (NULL);
	i = 0;
	k = 0;
	while (args && args[i])
	{
		split = ft_split(args[i], 2);
		j = 0;
		while (split && split[j])
			new_args[k++] = split[j++];
		free(split);
		free(args[i]);
		i++;
	}
	new_args[k] = NULL;
	free(args);
	return (new_args);
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
	node->args = split_all_args(node->args);
	expand_command_args_2(node, env, last_status, NULL);
}
