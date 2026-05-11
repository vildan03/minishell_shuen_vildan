/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vildan <vildan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:09:01 by vikaradu          #+#    #+#             */
/*   Updated: 2025/11/23 13:19:59 by vildan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;
	size_t	len_of_little;

	if (!*little)
		return ((char *) big);
	len_of_little = ft_strlen(little);
	b = 0;
	while (b < len && big[b] && b + len_of_little <= len)
	{
		l = 0;
		while (l < len_of_little && big[b + l] == little[l])
		{
			++l;
		}
		if (l == len_of_little)
		{
			return ((char *)(big + b));
		}
		++b;
	}
	return ((char *) NULL);
}

/*
int main()
{
    const char *big = "lolovlove you";
    const char *little = "love";
    size_t len = 13;
    printf("my function:%s\n", ft_strnstr(big, little, len));
    return 0;
}*/