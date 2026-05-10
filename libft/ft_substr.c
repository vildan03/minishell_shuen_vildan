/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vildan <vildan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:56:53 by vikaradu          #+#    #+#             */
/*   Updated: 2025/11/23 13:28:35 by vildan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start,
size_t len)
{
	char	*result;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
	{
		result = malloc(1);
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (i < len)
		result[i++] = s[start++];
	return (result);
}
