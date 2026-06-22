/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ast_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:53:56 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 10:53:57 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"
#include "parser_bonus.h"

static bool	has_quotes(char *value)
{
	int	i;

	i = 0;
	while (value[i])
	{
		if (value[i] == '\'' || value[i] == '"')
			return (true);
		i++;
	}
	return (false);
}

int	create_and_append_redir(t_ast_node *node, t_token *current)
{
	t_redir	*new_redir;

	if (current->next == NULL || current->next->type != TOKEN_WORD)
		return (0);
	new_redir = malloc(sizeof(t_redir));
	if (!new_redir)
		return (0);
	new_redir->type = translate_token_to_redir(current->type);
	new_redir->file = ft_strdup(current->next->value);
	new_redir->quoted = (new_redir->type == REDIR_HEREDOC
			&& has_quotes(current->next->value));
	if (!new_redir->file)
	{
		free(new_redir);
		return (0);
	}
	new_redir->next = NULL;
	append_redir_node(&(node->redir), new_redir);
	return (1);
}

void	extract_redirections(t_ast_node *node, t_token *start, t_token *end)
{
	t_token	*current;

	current = start;
	while (current != end)
	{
		if (current->type == TOKEN_REDIR_OUT || current->type == TOKEN_REDIR_IN
			|| current->type == TOKEN_APPEND || current->type == TOKEN_HEREDOC)
		{
			if (!create_and_append_redir(node, current))
				return ;
			current = current->next->next;
		}
		else
			current = current->next;
	}
}

int	count_args(t_token *start, t_token *end)
{
	int		count;
	t_token	*current;

	count = 0;
	current = start;
	while (current != end && current != NULL)
	{
		if (current->type == TOKEN_REDIR_OUT || current->type == TOKEN_REDIR_IN
			|| current->type == TOKEN_APPEND || current->type == TOKEN_HEREDOC)
		{
			if (current->next)
				current = current->next->next;
			else
				current = current->next;
		}
		else
		{
			if (current->value != NULL)
				count++;
			current = current->next;
		}
	}
	return (count);
}

char	**build_args_array(t_token *start, t_token *end)
{
	char	**args;
	int		i;

	args = malloc(sizeof(char *) * (count_args(start, end) + 1));
	if (!args)
		return (NULL);
	i = 0;
	while (start && start != end)
	{
		if (is_redir_ast(start->type))
		{
			start = start->next;
			if (start)
				start = start->next;
			continue ;
		}
		if (start->value)
		{
			args[i] = ft_strdup(start->value);
			i++;
		}
		start = start->next;
	}
	args[i] = NULL;
	return (args);
}
