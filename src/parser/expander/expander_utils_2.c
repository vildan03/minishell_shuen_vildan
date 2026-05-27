#include "minishell.h"

void toggle_quotes(char c, int *sq, int *dq)
{
    if (c == '\'' && !(*dq))
        *sq = !(*sq);
    else if (c == '"' && !(*sq))
        *dq = !(*dq);
}
