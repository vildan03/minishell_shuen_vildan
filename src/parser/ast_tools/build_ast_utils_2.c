#include "minishell.h"

t_token *find_last_op(t_token *start, t_token *end, int first_token, int second_token)
{
    t_token *current;
    t_token *last_op;
    int     paren_count;

    current = start;
    last_op = NULL;
    paren_count = 0;
    while(current != end)
    {
        if(paren_count == 0 && (current->type == first_token || current->type == second_token))
            last_op = current;
        
        if(current->type == TOKEN_LEFT_PAREN)
            paren_count++;
        else if(current->type == TOKEN_RIGHT_PAREN)
            paren_count--;
            
        current = current->next;
    }
    return (last_op);
}
void append_redir_node(t_redir **head, t_redir *new_node)
{
    t_redir *current;

    if (!head || !new_node)
        return;
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = new_node;
}

t_ast_node *create_ast_node(t_node_type type)
{
	t_ast_node *node;

	node = malloc(sizeof(*node));
	if(!node)
		return NULL;
	node->type = type;
	node->args = NULL;
	node->redir = NULL;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int is_redir_ast(int type)
{
    return (type == TOKEN_REDIR_OUT || type == TOKEN_REDIR_IN
        || type == TOKEN_APPEND || type == TOKEN_HEREDOC);
}
