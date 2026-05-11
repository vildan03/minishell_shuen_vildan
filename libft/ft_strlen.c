/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:08:53 by vikaradu          #+#    #+#             */
/*   Updated: 2025/11/24 11:08:32 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	result;

	result = 0;
	while (str[result])
	{
		result++;
	}
	return (result);
}

/*
void main(void)
{
    const char *str = "hello";
    printf("%ld",ft_strlen(str));
}
				*/