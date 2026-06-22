/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:53:27 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 18:05:29 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander_bonus.h"

bool	match_pattern_recursive(char *pattern, char *filename)
{
	if (*pattern == '\0')
		return (*filename == '\0');
	if (*pattern == '*')
	{
		if (match_pattern_recursive(pattern + 1, filename))
			return (true);
		return (*filename != '\0' && match_pattern_recursive(pattern, filename
				+ 1));
	}
	if (*pattern == 1)
	{
		if (*filename == '*')
			return (match_pattern_recursive(pattern, filename + 1));
		return (false);
	}
	if (*filename != '\0' && *pattern == *filename)
		return (match_pattern_recursive(pattern + 1, filename + 1));
	return (false);
}

bool	has_unquoted_star(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i])
	{
		if (str[i] == '*')
			return (true);
		i++;
	}
	return (false);
}

static int	wildcard_compare(char *s1, char *s2)
{
	char	*orig1;
	char	*orig2;
	int		c1;
	int		c2;

	orig1 = s1;
	orig2 = s2;
	while (*s1 || *s2)
	{
		while (*s1 && !ft_isalnum(*s1))
			s1++;
		while (*s2 && !ft_isalnum(*s2))
			s2++;
		if (!*s1 || !*s2)
			break ;
		c1 = ft_tolower(*s1++);
		c2 = ft_tolower(*s2++);
		if (c1 != c2)
			return (c1 - c2);
	}
	if (!*s1 && *s2)
		return (-1);
	if (*s1 && !*s2)
		return (1);
	return (ft_strcmp(orig1, orig2));
}

static char	**add_match_to_array(char **matches, char *new_match)
{
	int		target_index;
	int		j;
	int		count;
	char	**new_array;

	target_index = 0;
	count = 0;
	while (matches && matches[count])
		count++;
	while (target_index < count && wildcard_compare(matches[target_index],
			new_match) < 0)
		target_index++;
	new_array = malloc(sizeof(char *) * (count + 2));
	if (!new_array)
		return (NULL);
	j = -1;
	while (++j < target_index)
		new_array[j] = matches[j];
	new_array[j] = ft_strdup(new_match);
	while (++j <= count)
		new_array[j] = matches[j - 1];
	new_array[count + 1] = NULL;
	free(matches);
	return (new_array);
}

char	**get_wildcard_matches(char *pattern)
{
	DIR				*dir;
	struct dirent	*entry;
	char			**matches;

	matches = NULL;
	dir = opendir(".");
	if (!dir)
		return (NULL);
	entry = readdir(dir);
	while (entry != NULL)
	{
		if (match_pattern(pattern, entry->d_name))
		{
			matches = add_match_to_array(matches, entry->d_name);
		}
		entry = readdir(dir);
	}
	closedir(dir);
	return (matches);
}
