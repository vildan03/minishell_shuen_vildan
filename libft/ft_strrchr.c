/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:09:04 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 11:50:42 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *str, int c)
{
	int	len;

	len = 0;
	c = (unsigned char)c;
	while (str[len])
	{
		len++;
	}
	while (len >= 0)
	{
		if (str[len] == c)
		{
			return ((char *)(str + len));
		}
		len--;
	}
	return ((char *)NULL);
}

/*
int	main(void)
{
	char	*s;
	char	*p;

	s = "true";
	p = ft_strrchr(s, 't' + 256);
	if (p != NULL)
	{
		printf("last char is: %c\n", *p);
	}
	else
	{
		printf("Character not found.\n");
	}
	return (0);
}
*/