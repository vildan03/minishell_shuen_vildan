/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:53:23 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 17:50:03 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	**splice_wildcard_matches(char **args, char **matches, int target_index)
{
	char	**new_args;
	int		args_len;
	int		matches_len;
	int		j;
	int		k;

	args_len = count_contents(args);
	matches_len = count_contents(matches);
	j = 0;
	k = 0;
	new_args = malloc(sizeof(char *) * (args_len + matches_len));
	while (k < target_index)
		new_args[j++] = args[k++];
	k = 0;
	while (matches[k] != NULL)
		new_args[j++] = matches[k++];
	k = target_index + 1;
	while (args[k] != NULL)
		new_args[j++] = args[k++];
	new_args[j] = NULL;
	free(args[target_index]);
	free(args);
	free(matches);
	return (new_args);
}

void	expand_wildcards(t_ast_node *node)
{
	int		i;
	char	**matches;
	int		matches_count;

	i = 0;
	if (!node || !node->args)
		return ;
	while (node->args[i])
	{
		if (has_unquoted_star(node->args[i]))
		{
			matches = get_wildcard_matches(node->args[i]);
			if (matches && matches[0] != NULL)
			{
				matches_count = count_contents(matches);
				node->args = splice_wildcard_matches(node->args, matches, i);
				i += matches_count - 1;
			}
			else if (matches)
				free(matches);
		}
		i++;
	}
}
