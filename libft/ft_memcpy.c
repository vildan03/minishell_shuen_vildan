/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:08:00 by vikaradu          #+#    #+#             */
/*   Updated: 2025/11/24 15:19:46 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		++i;
	}
	return (dest);
}

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
    char src[5] = "hello";
    char dest[6];
    size_t n = 5;
    int i = 0;
				memcpy(dest, src, NULL);
    while(i < 6)
    {
    printf("%c",dest[i]);
    ++i;
    }
}
*/