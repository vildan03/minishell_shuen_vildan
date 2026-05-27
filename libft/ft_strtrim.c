/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vildan <vildan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:09:07 by vikaradu          #+#    #+#             */
/*   Updated: 2025/11/23 13:26:26 by vildan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	in_charset(char c, const char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
	{
		if (charset[i] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	r;
	char	*result;

	i = 0;
	r = 0;
	while (s1[i] && (in_charset(s1[i], set) == 1))
		++i;
	if (s1[i] == '\0')
		return ((ft_strdup("")));
	j = ft_strlen(s1) - 1;
	while ((in_charset(s1[j], set) == 1))
		--j;
	result = malloc(j - i + 2);
	if (!result)
		return (NULL);
	while (i <= j)
		result[r++] = s1[i++];
	result[r] = '\0';
	return (result);
}
