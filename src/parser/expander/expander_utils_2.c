#include "minishell.h"

void toggle_quotes(char c, int *sq, int *dq)
{
    if (c == '\'' && !(*dq))
        *sq = !(*sq);
    else if (c == '"' && !(*sq))
        *dq = !(*dq);
}

int has_quotes(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        if (str[i] == '\'' || str[i] == '\"')
            return (1);
        i++;
    }
    return (0);
}

void remove_empty_arg(char **args, int index)
{
    while (args[index])
    {
        args[index] = args[index + 1];
        index++;
    }
}
