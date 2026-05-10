/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:08:32 by vikaradu          #+#    #+#             */
/*   Updated: 2025/11/24 12:08:03 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			return ((char *)(str + i));
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)(str + i));
	}
	return (NULL);
}

/*
int main()
{
    char *s = "find the letter z";
    char *p = ft_strchr(s, 'z');

    if (p != NULL)
    {
        printf("char is: %c\n", *p);
    }
    else
    {
        printf("Character not found.\n");
    }

    return (0);
}
*/