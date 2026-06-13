#include "minishell.h"
#include "parser.h"

t_token	*find_top_op(t_token *start, t_token *end, int op1, int op2)
{
	t_token	*current;
	t_token	*last_op;
	int		depth;

	current = start;
	last_op = NULL;
	depth = 0;
	while (current && current != end)
	{
		if (current->type == TOKEN_LEFT_PAREN)
			depth++;
		else if (current->type == TOKEN_RIGHT_PAREN)
			depth--;
		else if (depth == 0 && (current->type == op1 || current->type == op2))
			last_op = current;
		current = current->next;
	}
	return (last_op);
}

t_token	*find_matching_paren(t_token *start, t_token *end)
{
	t_token	*current;
	int		depth;

	current = start;
	depth = 0;
	while (current && current != end)
	{
		if (current->type == TOKEN_LEFT_PAREN)
			depth++;
		else if (current->type == TOKEN_RIGHT_PAREN)
			depth--;
		if (depth == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	append_redir_node(t_redir **head, t_redir *new_node)
{
	t_redir	*current;

	if (!head || !new_node)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

t_ast_node	*create_ast_node(t_node_type type)
{
	t_ast_node	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->type = type;
	node->args = NULL;
	node->redir = NULL;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int	is_redir_ast(int type)
{
	return (type == TOKEN_REDIR_OUT || type == TOKEN_REDIR_IN
		|| type == TOKEN_APPEND || type == TOKEN_HEREDOC);
}

t_token	*get_last_token(t_token *start, t_token *end)
{
	t_token	*current;
	t_token	*last_token;

	current = start;
	last_token = NULL;
	// We added: && current->type != TOKEN_EOF
	while (current != end && current->type != TOKEN_EOF)
	{
		last_token = current;
		current = current->next;
	}
	return (last_token);
}

t_redir_type	translate_token_to_redir(t_token_type type)
{
	if (type == TOKEN_REDIR_OUT)
		return (REDIR_OUT);
	if (type == TOKEN_REDIR_IN)
		return (REDIR_IN);
	if (type == TOKEN_APPEND)
		return (REDIR_APPEND);
	return (REDIR_HEREDOC);
}
