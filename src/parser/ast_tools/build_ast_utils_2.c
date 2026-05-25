#include "minishell.h"

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
