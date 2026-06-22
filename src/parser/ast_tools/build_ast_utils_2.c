/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ast_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:53:51 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 10:53:52 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"

t_token	*find_top_op(t_token *start, t_token *end, int op1, int op2)
{
	t_token	*current;
	t_token	*last_op;
	int		depth;

	current = start;
	last_op = NULL;
	depth = 0;
	while (current && current != end)
	{
		if (current->type == TOKEN_LEFT_PAREN)
			depth++;
		else if (current->type == TOKEN_RIGHT_PAREN)
			depth--;
		else if (depth == 0 && (current->type == op1 || current->type == op2))
			last_op = current;
		current = current->next;
	}
	return (last_op);
}

t_token	*find_matching_paren(t_token *start, t_token *end)
{
	t_token	*current;
	int		depth;

	current = start;
	depth = 0;
	while (current && current != end)
	{
		if (current->type == TOKEN_LEFT_PAREN)
			depth++;
		else if (current->type == TOKEN_RIGHT_PAREN)
			depth--;
		if (depth == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	append_redir_node(t_redir **head, t_redir *new_node)
{
	t_redir	*current;

	if (!head || !new_node)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}
