/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:58:16 by vikaradu          #+#    #+#             */
/*   Updated: 2025/11/24 15:56:25 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**allocate_substrings(char const *s, char c)
{
	int		count;
	int		i;
	int		in_word;
	char	**substrings;

	i = 0;
	in_word = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			++count;
		}
		i++;
	}
	substrings = (char **)malloc(sizeof(char *) * (count + 1));
	if (!substrings)
		return (NULL);
	return (substrings);
}

int	word_len(char const *s, int i, char c)
{
	int	length;

	length = 0;
	while (s[i + length] && (s[i + length] != c))
		++length;
	return (length);
}

char	**ft_split(char const *s, char c)
{
	char	**substrings;
	char	**result;
	int		i;
	int		j;

	(1 && (substrings = allocate_substrings(s, c), result = substrings));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		while ((s[i] == c) && s[i])
			++i;
		if (s[i] == '\0')
			break ;
		*substrings = (char *)malloc(sizeof(char) * word_len(s, i, c) + 1);
		if (!(*substrings))
			return (NULL);
		j = 0;
		while (s[i] && (s[i] != c))
			(*substrings)[j++] = s[i++];
		(*substrings++)[j] = '\0';
	}
	*substrings = NULL;
	return (result);
}

// #include <stdlib.h>
// int main(void)
// {
//     char const *s = "hicju";
//     char **substrings = ft_split(s, 'c');
//     if (!substrings) {
//         printf("ft_split returned NULL\n");
//         return (1);
//     }
//     for (int i = 0; substrings[i] != NULL; i++)
//         printf("sub[%d] = %s\n", i, substrings[i]);
//     return (0);
// }
