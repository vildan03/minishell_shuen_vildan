/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:07:57 by vikaradu          #+#    #+#             */
/*   Updated: 2025/11/20 18:37:41 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1 = s1;
	const unsigned char	*str2 = s2;

	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		++i;
	}
	return (0);
}
/*
int main ()
{
	const unsigned char *s1 = (const unsigned char *)"hi";
	const unsigned char *s2 = (const unsigned char *)"hello";
	size_t n = 5;
	printf("%d",ft_memcmp(s1,s2,n));
}*/