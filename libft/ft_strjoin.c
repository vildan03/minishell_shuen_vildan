/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:47:58 by vikaradu          #+#    #+#             */
/*   Updated: 2025/11/24 09:13:22 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int				i;
	int				s;
	const size_t	len_s1 = ft_strlen(s1);
	const size_t	len_s2 = ft_strlen(s2);
	char			*result;

	i = 0;
	s = 0;
	result = malloc(len_s1 + len_s2 + 1);
	if (!result)
		return (NULL);
	while (s1[s])
		result[i++] = s1[s++];
	s = 0;
	while (s2[s])
		result[i++] = s2[s++];
	result[i] = '\0';
	return (result);
}
