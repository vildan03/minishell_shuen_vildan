#include "parser.h"

bool is_valid_combo(t_token *token, int *paren_count)
{
	int type;
	int next_type;

	type = token->type;
	next_type = TOKEN_EOF;
	if(type != TOKEN_EOF)
		next_type = token->next->type;
	if((is_redir(type) || is_binary_op(type)) && (next_type != TOKEN_WORD || next_type == TOKEN_RIGHT_PAREN))
		return false;
	else if((is_binary_op(type) || type == TOKEN_LEFT_PAREN) && is_binary_op(next_type))
		return false;
	else if(type == TOKEN_WORD && next_type == TOKEN_LEFT_PAREN)
		return false;
	else if(next_type == TOKEN_EOF && is_binary_op(type))
		return false;
	else if(type == TOKEN_LEFT_PAREN && next_type == TOKEN_RIGHT_PAREN)
		return false;
	if(type == TOKEN_LEFT_PAREN)
		(*paren_count)++;
	if(type == TOKEN_RIGHT_PAREN)
		(*paren_count)--;
	if(*paren_count < 0)
		return false;
	return true;
}

int check_valid_syntax(t_token *token)
{
	t_token *current;
	int paren_count;

	current = token;
	paren_count = 0;
	if(is_binary_op(current->type) == true)
		return (print_syntax_err("syntax error near unexpected token ", token->value), 1);
	while(current->type != TOKEN_EOF)
	{
		if(is_valid_combo(current, &paren_count) == false)
		{
			if(current->next->type == TOKEN_EOF)
				return(print_syntax_err("syntax error near unexpected token ", "newline"), 1);
			return(print_syntax_err("syntax error near unexpected token ", current->next->value), 1);
		}
		current = current->next;
	}
	if(paren_count != 0)
		return(print_syntax_err("unexpected EOF while looking for matching ')'", NULL), 1);
	return 0;
}
