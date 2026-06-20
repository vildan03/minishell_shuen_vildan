#include "parser.h"

bool	is_word(char x)
{
	if (x == '\t' || x == ' ' || x == '|' || x == '<' || x == '>' || x == '('
		|| x == ')' || x == '&')
		return (false);
	return (true);
}

void	free_token_list(t_token *token)
{
	t_token	*current;
	t_token	*next_node;

	current = token;
	while (current != NULL)
	{
		next_node = current->next;
		if (current->value)
			free(current->value);
		free(current);
		current = next_node;
	}
}
