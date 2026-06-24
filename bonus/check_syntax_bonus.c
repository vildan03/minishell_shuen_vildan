/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:54:21 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/24 12:27:48 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

static bool	check_paren_combo(int type, int next, int *paren_count)
{
	if (type == TOKEN_LEFT_PAREN)
		(*paren_count)++;
	else if (type == TOKEN_RIGHT_PAREN)
		(*paren_count)--;
	if (*paren_count < 0 || (type == TOKEN_WORD && next == TOKEN_LEFT_PAREN)
		|| (type == TOKEN_LEFT_PAREN && next == TOKEN_RIGHT_PAREN))
		return (false);
	if (is_redir(type) && next != TOKEN_WORD)
		return (false);
	if (is_binary_op(type) && (next == TOKEN_RIGHT_PAREN || next == TOKEN_EOF
			|| is_binary_op(next)))
		return (false);
	return (true);
}

static bool	is_valid_combo(t_token *token, int *paren_count)
{
	int	type;
	int	next;

	type = token->type;
	if (token->next)
		next = token->next->type;
	else
		next = TOKEN_EOF;
	if (check_paren_combo(type, next, paren_count) == false)
		return (false);
	if (type == TOKEN_LEFT_PAREN && is_binary_op(next))
		return (false);
	if (type == TOKEN_RIGHT_PAREN && (next == TOKEN_WORD
			|| next == TOKEN_LEFT_PAREN))
		return (false);
	return (true);
}

static int	print_combo_error(t_token *current)
{
	if (!current->next || current->next->type == TOKEN_EOF)
		return (print_syntax_err("syntax error near unexpected token ",
				"newline"), 2);
	return (print_syntax_err("syntax error near unexpected token ",
			current->next->value), 1);
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
		if (current->type == TOKEN_AMP || is_valid_combo(current,
				&paren_count) == false)
			return (print_combo_error(current));
		current = current->next;
	}
	if (paren_count != 0)
		return (print_syntax_err("unexpected EOF while looking for matching ')
		'", NULL), 1);
	return (0);
}
