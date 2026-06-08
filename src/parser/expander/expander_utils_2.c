#include "expander.h"

void	toggle_quotes(char c, int *sq, int *dq)
{
	if (c == '\'' && !(*dq))
		*sq = !(*sq);
	else if (c == '"' && !(*sq))
		*dq = !(*dq);
}

void	expand_redirections(t_redir *redir_list, char **env, int status)
{
	t_redir	*current;
	char	*expanded_file;

	current = redir_list;
	while (current != NULL)
	{
		expanded_file = expand_string(current->file, env, status);
		free(current->file);
		current->file = expanded_file;
		current = current->next;
	}
}

int	count_valid_args(char **args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (args[i] != NULL)
	{
		if (args[i][0] != '\0')
			count++;
		i++;
	}
	return (count);
}
