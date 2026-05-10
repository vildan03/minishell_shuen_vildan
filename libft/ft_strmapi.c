/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:08:58 by vikaradu          #+#    #+#             */
/*   Updated: 2025/11/20 18:08:59 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned
int, char))
{
	unsigned int		i;
	char				*result;

	i = 0;
	result = malloc(ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = (f(i, s[i]));
		++i;
	}
	result[i] = '\0';
	return (result);
}
