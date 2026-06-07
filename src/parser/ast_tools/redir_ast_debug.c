#include "minishell.h"
#include "parser.h"

void debug_print_command(t_ast_node *node)
{
    int     i = 0;
    t_redir *tmp;

    if (!node || node->type != NODE_COMMAND)
        return ;
    
    printf("\n=== AST NODE X-RAY ===\n");
    
    // 1. Print the arguments that execve will get
    printf("[ARGS]: ");
    while (node->args && node->args[i])
    {
        printf("'%s' ", node->args[i]);
        i++;
    }
    printf("\n");

    // 2. Print the redirection backpack
    printf("[REDIRS]:\n");
    tmp = node->redir;
    if (!tmp)
        printf("  (None)\n");
    while (tmp)
    {
        printf("  -> Type: %d | File: '%s'\n", tmp->type, tmp->file);
        tmp = tmp->next;
    }
    printf("======================\n\n");
}
