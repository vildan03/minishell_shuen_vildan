/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:53:59 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 18:21:37 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"
#include "parser_bonus.h"

t_ast_node	*parse_command(t_token *start, t_token *end)
{
	t_ast_node	*node;

	if (!start || start == end || start->type == TOKEN_EOF)
		return (NULL);
	node = create_ast_node(NODE_COMMAND);
	if (!node)
		return (NULL);
	extract_redirections(node, start, end);
	node->args = build_args_array(start, end);
	return (node);
}

t_ast_node	*parse_pipe(t_token *start, t_token *end)
{
	t_ast_node	*node;
	t_token		*last_pipe;

	last_pipe = find_top_op(start, end, TOKEN_PIPE, -1);
	if (!last_pipe)
		return (parse_element(start, end));
	node = create_ast_node(NODE_PIPE);
	if (!node)
		return (NULL);
	node->left = parse_pipe(start, last_pipe);
	node->right = parse_element(last_pipe->next, end);
	return (node);
}

t_ast_node	*parse_element(t_token *start, t_token *end)
{
	t_ast_node	*node;
	t_token		*match;

	if (!start || start == end || start->type == TOKEN_EOF)
		return (NULL);
	if (start->type == TOKEN_LEFT_PAREN)
	{
		match = find_matching_paren(start, end);
		if (match)
		{
			node = create_ast_node(NODE_SUBSHELL);
			node->left = parse_logic(start->next, match);
			extract_redirections(node, match->next, end);
			return (node);
		}
	}
	return (parse_command(start, end));
}

t_ast_node	*parse_logic(t_token *start, t_token *end)
{
	t_ast_node	*node;
	t_token		*last_op;

	last_op = find_top_op(start, end, TOKEN_AND, TOKEN_OR);
	if (!last_op)
		return (parse_pipe(start, end));
	if (last_op->type == TOKEN_AND)
		node = create_ast_node(NODE_AND);
	else
		node = create_ast_node(NODE_OR);
	if (!node)
		return (NULL);
	node->left = parse_logic(start, last_op);
	node->right = parse_pipe(last_op->next, end);
	return (node);
}
