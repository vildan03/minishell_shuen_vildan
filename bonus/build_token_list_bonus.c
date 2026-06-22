/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_token_list_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:54:06 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 10:54:07 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

t_token	*create_new_token(void)
{
	t_token	*new_token;

	new_token = malloc(sizeof(*new_token));
	if (!new_token)
		return (NULL);
	new_token->type = TOKEN_EOF;
	new_token->value = NULL;
	new_token->next = NULL;
	return (new_token);
}

int	get_word_value(char *input, int *i, t_token *token)
{
	char	in_quotes;
	int		start;

	in_quotes = 0;
	start = *i;
	while (input[*i])
	{
		if (!in_quotes && !is_word(input[*i]))
			break ;
		if (!in_quotes && (input[*i] == '"' || input[*i] == '\''))
			in_quotes = input[*i];
		else if (in_quotes == input[*i])
			in_quotes = 0;
		(*i)++;
	}
	token->value = ft_substr(input, start, *i - start);
	if (!token->value)
		return (1);
	if (in_quotes)
		return (token->type = TOKEN_EOF,
			print_syntax_err("unexpected EOF while looking for matching ",
				&in_quotes), 1);
	return (0);
}

int	get_token_type(char *input, int i)
{
	int	type;

	if (input[i] == '>' && input[i + 1] == '>')
		type = TOKEN_APPEND;
	else if (input[i] == '<' && input[i + 1] == '<')
		type = TOKEN_HEREDOC;
	else if (input[i] == '|' && input[i + 1] == '|')
		type = TOKEN_OR;
	else if (input[i] == '&' && input[i + 1] == '&')
		type = TOKEN_AND;
	else if (input[i] == '&')
		type = TOKEN_AND;
	else if (input[i] == '>')
		type = TOKEN_REDIR_OUT;
	else if (input[i] == '<')
		type = TOKEN_REDIR_IN;
	else if (input[i] == '|')
		type = TOKEN_PIPE;
	else if (input[i] == '(')
		type = TOKEN_LEFT_PAREN;
	else if (input[i] == ')')
		type = TOKEN_RIGHT_PAREN;
	else
		type = TOKEN_WORD;
	return (type);
}

int	get_token_value(char *input, int *i, t_token *token)
{
	int	type;

	type = token->type;
	if (type == TOKEN_APPEND || type == TOKEN_HEREDOC || type == TOKEN_AND
		|| type == TOKEN_OR)
	{
		token->value = ft_substr(input, *i, 2);
		*i += 2;
	}
	else if (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_OUT
		|| type == TOKEN_PIPE || type == TOKEN_LEFT_PAREN
		|| type == TOKEN_RIGHT_PAREN || type == TOKEN_AMP)
	{
		token->value = ft_substr(input, *i, 1);
		(*i)++;
	}
	else if (token->type == TOKEN_WORD)
	{
		if (get_word_value(input, i, token) != 0)
			return (1);
	}
	return (0);
}

t_token	*construct_token_list(char *input, t_token *token_list)
{
	int		i;
	t_token	*current;

	i = 0;
	if (!input)
		return (NULL);
	token_list = create_new_token();
	current = token_list;
	while (input[i] != '\0')
	{
		while (ft_isspace(input[i]))
			i++;
		if (input[i] == '\0')
			break ;
		current->type = get_token_type(input, i);
		if (get_token_value(input, &i, current) != 0)
			return (free_token_list(current), NULL);
		current->next = create_new_token();
		current = current->next;
		if (input[i] == '\0')
			break ;
	}
	if (input[i] == '\0')
		current->type = TOKEN_EOF;
	return (token_list);
}
