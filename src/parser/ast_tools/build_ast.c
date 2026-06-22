/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:53:59 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 10:54:00 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"

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
