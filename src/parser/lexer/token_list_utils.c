#include "expander.h"
#include "parser.h"

bool	is_word(char x)
{
	if (x == '\t' || x == ' ' || x == '|' || x == '<' || x == '>' || x == '('
		|| x == ')' || x == '&')
		return (false);
	return (true);
}

int	append_word_char(char **value, char *input, int *i, char in_quotes)
{
	if (!in_quotes && input[*i] == '\\' && input[*i + 1])
	{
		*value = append_char(*value, input[*i + 1]);
		if (!*value)
			return (1);
		*i += 2;
		return (0);
	}
	*value = append_char(*value, input[*i]);
	if (!*value)
		return (1);
	(*i)++;
	return (0);
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
