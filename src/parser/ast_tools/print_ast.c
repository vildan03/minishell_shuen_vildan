#include "minishell.h"

void print_spaces(int depth)
{
    int i = 0;
    while (i < depth)
    {
        printf("    ");
        i++;
    }
}

void print_command_node(t_ast_node *node)
{
    int i;

    printf("[CMD: ");
    i = 0;
    while (node->args && node->args[i])
    {
        printf("'%s' ", node->args[i]);
        i++;
    }
    if (node->redir != NULL)
        printf(" (+redirs)");
    printf("]\n");
}

void print_ast(t_ast_node *node, int depth)
{
    if (node == NULL)
        return ;
    print_ast(node->right, depth + 1);
    print_spaces(depth);
    if (node->type == NODE_PIPE)
        printf("[PIPE |]\n");
    else if (node->type == NODE_AND)
        printf("[AND &&]\n");
    else if (node->type == NODE_OR)
        printf("[OR ||]\n");
    else if (node->type == NODE_SUBSHELL)
        printf("[SUBSHELL ()]\n");
    else if (node->type == NODE_COMMAND)
        print_command_node(node);
    print_ast(node->left, depth + 1);
}
