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

t_token *get_last_token(t_token *start, t_token *end)
{
    t_token *current;
    t_token *last_token;

    current = start;
    last_token = NULL;
    while(current != end)
    {
        if(current->next == end)
            last_token = current;
        current = current->next;
    }
    return (last_token);
}

void extract_redirections(t_ast_node *node, t_token *start, t_token *end)
{
    t_token *current = start;
    t_redir *new_redir;

    while (current != end)
    {
        if (current->type == TOKEN_REDIR_OUT || current->type == TOKEN_REDIR_IN ||
            current->type == TOKEN_APPEND || current->type == TOKEN_HEREDOC)
        {
            new_redir = malloc(sizeof(t_redir));
	    if(!new_redir)
		    return;
            new_redir->type = current->type;
            new_redir->file = ft_strdup(current->next->value);
	    if(!new_redir->file)
		    return;
            new_redir->next = NULL;
            append_redir_node(&(node->redir), new_redir);
            current = current->next->next;
        }
        else
            current = current->next;
    }
}

int count_args(t_token *start, t_token *end)
{
    int     count = 0;
    t_token *current = start;

    while (current != end && current != NULL) 
    {
        if (current->type == TOKEN_REDIR_OUT || current->type == TOKEN_REDIR_IN ||
            current->type == TOKEN_APPEND || current->type == TOKEN_HEREDOC)
        {
            if (current->next)
                current = current->next->next;
            else
                current = current->next;
        }
        else
        {
            if (current->value != NULL)
                count++;
            
            current = current->next;
        }
    }
    return (count);
}

char **build_args_array(t_token *start, t_token *end)
{
    char    **args;
    int     arg_count;
    int     i;
    t_token *current;

    arg_count = count_args(start, end);
    args = malloc(sizeof(char *) * (arg_count + 1));
    if (!args)
        return (NULL);
    i = 0;
    current = start;
    while (current != end && current != NULL)
    {
        if (current->type == TOKEN_REDIR_OUT || current->type == TOKEN_REDIR_IN ||
            current->type == TOKEN_APPEND || current->type == TOKEN_HEREDOC)
        {
            if (current->next)
                current = current->next->next;
            else
                current = current->next;
        }
        else
        {
            if (current->value != NULL)
            {
                args[i] = ft_strdup(current->value);
                i++;
            }
            current = current->next;
        }
    }
    args[i] = NULL;
    return (args);
}
