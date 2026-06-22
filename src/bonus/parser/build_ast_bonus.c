#include "minishell.h"
#include "parser.h"

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
