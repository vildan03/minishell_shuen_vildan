#include "minishell.h"
#include "parser.h"

void free_string_array(char **arr)
{
    int i;

    if (!arr)
        return;
    i = 0;
    while (arr[i] != NULL)
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void free_redir(t_redir *head)
{
    t_redir *current;
    t_redir *next;

    current = head;
    while (current != NULL)
    {
        next = current->next;
        if (current->file != NULL)
            free(current->file);
        free(current);
        current = next;
    }
}

void free_ast(t_ast_node *node)
{
    if (node == NULL)
        return;

    free_ast(node->left);
    
    free_ast(node->right);

    if (node->args != NULL)
        free_string_array(node->args);
        
    if (node->redir != NULL)
        free_redir(node->redir);

    free(node);
}
