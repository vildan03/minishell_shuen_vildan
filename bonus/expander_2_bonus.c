/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:53:12 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 17:19:11 by kerlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander_bonus.h"

static char	*extract_and_replace_var(t_expand_ctx *ctx)
{
	int		start;
	char	*key;
	char	*val_dup;
	int		j;

	ctx->i++;
	if (ctx->raw[ctx->i] == '?')
		return (ctx->i++, ft_itoa(ctx->status));
	if (ft_isdigit(ctx->raw[ctx->i]))
		return (ctx->i++, ft_strdup(""));
	start = ctx->i;
	while (ctx->raw[ctx->i] && (ft_isalnum(ctx->raw[ctx->i])
			|| ctx->raw[ctx->i] == '_'))
		ctx->i++;
	key = ft_substr(ctx->raw, start, ctx->i - start);
	val_dup = ft_strdup(get_env_value(ctx->env, key));
	free(key);
	j = -1;
	while (!ctx->dq && val_dup && val_dup[++j])
	{
		if (val_dup[j] == ' ' || val_dup[j] == '\t' || val_dup[j] == '\n')
			val_dup[j] = 2;
	}
	return (val_dup);
}

static char	*process_var(t_expand_ctx *ctx)
{
	char	*tmp;

	tmp = extract_and_replace_var(ctx);
	ctx->res = append_string(ctx->res, tmp);
	free(tmp);
	return (ctx->res);
}

char	*expand_string_2(t_expand_ctx *ctx)
{
	ctx->skip_inc = 0;
	if (ctx->raw[ctx->i] == '$' && !ctx->sq && is_env_char(ctx->raw[ctx->i
			+ 1]))
	{
		ctx->skip_inc = 1;
		return (process_var(ctx));
	}
	if (ctx->raw[ctx->i] == '*' && (ctx->sq || ctx->dq))
		return (append_char(ctx->res, 1));
	return (append_char(ctx->res, ctx->raw[ctx->i]));
}

void	filter_empty_args(t_ast_node *node, char **new_args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (node->args[i] != NULL)
	{
		if (node->args[i][0] != '\0')
			new_args[j++] = node->args[i];
		else
			free(node->args[i]);
		i++;
	}
	new_args[j] = NULL;
	free(node->args);
	node->args = new_args;
}

void	unmask_args(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args && args[i])
	{
		if (args[i][0] == 3 && args[i][1] == '\0')
			args[i][0] = '\0';
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == 1)
				args[i][j] = '*';
			j++;
		}
		i++;
	}
}
