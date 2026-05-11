/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vildan <vildan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:06:42 by vikaradu          #+#    #+#             */
/*   Updated: 2025/11/23 13:30:42 by vildan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
	{
		return (c - ('a' - 'A'));
	}
	return (c);
}

/*
int main() 
{
    char str[] = "nAabiyoN2?!";
    int i = 0;
    while (str[i] != '\0') {
        str[i] = ft_toupper(str[i]);
        i++;
    }

    printf("Upper verison: %s\n", str);
    return 0;
}
*/