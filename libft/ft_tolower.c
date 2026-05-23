/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vildan <vildan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:09:15 by vikaradu          #+#    #+#             */
/*   Updated: 2025/11/23 13:29:55 by vildan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
	{
		return (c + ('a' - 'A'));
	}
	return (c);
}

/*
int	main(void)
{
	char	str[] = "BonJouR234.!";
	int		i;

	i = 0;
	while (str[i] != '\0') {
		str[i] = ft_tolower(str[i]);
		i++;
	}
	printf("Lowercase versoin: %s\n", str);
	return (0);
}
*/