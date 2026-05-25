#include "minishell.h"

t_ast_node *parse_command(t_token *start, t_token *end)
{
	t_ast_node *node;
	t_token *last_token;
	
	last_token = get_last_token(start, end);
	if(!start || !last_token)
		return (NULL);
	if(start->type == TOKEN_LEFT_PAREN && last_token->type == TOKEN_RIGHT_PAREN)
	{
		node = create_ast_node(NODE_SUBSHELL);
		node->left = parse_logic(start->next, last_token);
		return node;
	}
	node = create_ast_node(NODE_COMMAND);
	extract_redirections(node, start, end);
	node->args = build_args_array(start, end);
	return node;
}

t_ast_node *parse_pipe(t_token *start, t_token *end)
{
	t_token *last_pipe;
	t_ast_node *node;

	last_pipe = find_last_op(start, end, TOKEN_PIPE, -1);
	if(last_pipe == NULL)
		return (parse_command(start, end));
	node = create_ast_node(NODE_PIPE);
	node->left = parse_pipe(start, last_pipe);
	node->right = parse_command(last_pipe->next, end);
	return (node);
}

t_ast_node *parse_logic(t_token *start, t_token *end)
{
	t_ast_node *node;
	t_token *last_op;

	last_op = find_last_op(start, end, TOKEN_AND, TOKEN_OR);
	node = NULL;
	if(last_op == NULL)
		return (parse_pipe(start, end));
	if(last_op->type == TOKEN_AND)
		node = create_ast_node(NODE_AND);
	else if(last_op->type == TOKEN_OR)
		node = create_ast_node(NODE_OR);
	if(node == NULL)
		return NULL;
	node->left = parse_logic(start, last_op);
	node->right = parse_pipe(last_op->next, end);
	return node;
}
