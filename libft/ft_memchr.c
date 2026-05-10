/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:07:55 by vikaradu          #+#    #+#             */
/*   Updated: 2025/11/20 18:37:39 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	c = (unsigned char) c;
	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (str[i] == c)
			return ((void *)(str + i));
		i++;
	}
	return ((void *) NULL);
}

/*
int main()
{
    char *s = "hello";
    size_t n = 5;
    void *result = ft_memchr(s,'e',n);
    if (result != NULL)
    {
    printf("it found the byte and here is the adress:%p\n", result);
    printf("here is the pointer:%s\n", (unsigned char *)result);

    }
    else
    printf("could not find it"); 



}*/