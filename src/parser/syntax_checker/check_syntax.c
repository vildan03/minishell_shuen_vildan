#include "parser.h"

bool	is_valid_combo(t_token *token, int *paren_count)
{
	int	type;
	int	next;

	type = token->type;
	next = TOKEN_EOF;
	if (type != TOKEN_EOF && token->next)
		next = token->next->type;
	if (type == TOKEN_LEFT_PAREN)
		(*paren_count)++;
	else if (type == TOKEN_RIGHT_PAREN)
		(*paren_count)--;
	if (*paren_count < 0 || (type == TOKEN_WORD && next == TOKEN_LEFT_PAREN)
		|| (type == TOKEN_LEFT_PAREN && next == TOKEN_RIGHT_PAREN))
		return (false);
	if (is_redir(type) && next != TOKEN_WORD)
		return (false);
	if (is_binary_op(type) && (next == TOKEN_RIGHT_PAREN
			|| next == TOKEN_EOF || is_binary_op(next)))
		return (false);
	if (type == TOKEN_LEFT_PAREN && is_binary_op(next))
		return (false);
	return (true);
}

int	check_valid_syntax(t_token *token)
{
	t_token	*current;
	int		paren_count;

	current = token;
	paren_count = 0;
	if (is_binary_op(current->type) == true)
		return (print_syntax_err("syntax error near unexpected token ",
				token->value), 1);
	while (current->type != TOKEN_EOF)
	{
		if (is_valid_combo(current, &paren_count) == false)
		{
			if (current->next->type == TOKEN_EOF)
				return (print_syntax_err("syntax error near unexpected token ",
						"newline"), 1);
			return (print_syntax_err("syntax error near unexpected token ",
					current->next->value), 1);
		}
		current = current->next;
	}
	if (paren_count != 0)
		return (print_syntax_err("unexpected EOF while looking for matching ')'",
				NULL), 1);
	return (0);
}
