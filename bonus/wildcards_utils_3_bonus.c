/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_utils_3_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 17:49:37 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 17:52:12 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander_bonus.h"

int	count_contents(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		i++;
	return (i);
}

bool	match_pattern(char *pattern, char *filename)
{
	if (!pattern || !filename)
		return (false);
	if ((filename[0] == '.' && filename[1] == '\0') || (filename[0] == '.'
			&& filename[1] == '.' && filename[2] == '\0'))
		return (false);
	if (filename[0] == '.' && pattern[0] != '.')
		return (false);
	return (match_pattern_recursive(pattern, filename));
}
