#include "parser.h"

bool ft_isspace(char a)
{
	if(a == ' ' || (a >= '\t' && a <= '\r'))
		return true;
	return false;
}

bool is_word(char x)
{
	if(x == '\t' || x == ' ' || x == '|' || x == '<' || x == '>' || x == '(' || x == ')' || x == '&')
		return false;
	return true;
}

void print_tokens(t_token *token_list)
{
	t_token *current;

	current = token_list;
	while(current->type != TOKEN_EOF)
	{
		printf("%d = %s\n", current->type, current->value);
		current = current->next;
	}
}

void free_token_list(t_token *token)
{
    t_token *current;
    t_token *next_node;

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
