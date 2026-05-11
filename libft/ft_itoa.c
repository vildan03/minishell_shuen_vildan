/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:07:17 by vikaradu          #+#    #+#             */
/*   Updated: 2025/11/20 18:07:18 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	count_digits(long c)
{
	int	digits;

	digits = 1;
	while (c > 9)
	{
		++digits;
		c = c / 10;
	}
	return (digits);
}

char	*ft_itoa_negative(long n)
{
	char	*result;
	int		digits;

	n = -n;
	digits = (count_digits(n));
	result = malloc(digits + 2);
	if (!result)
		return (NULL);
	result[0] = '-';
	result[digits + 1] = '\0';
	while (n > 0)
	{
		result[digits--] = (n % 10) + '0';
		n = n / 10;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		digits;
	long	long_num;

	long_num = n;
	if (long_num < 0)
		return (ft_itoa_negative(long_num));
	digits = count_digits(long_num);
	result = malloc(digits + 1);
	if (!result)
		return (NULL);
	result[digits] = '\0';
	if (long_num == 0)
		result[0] = '0';
	while (long_num > 0)
	{
		result[--digits] = (long_num % 10) + '0';
		long_num = long_num / 10;
	}
	return (result);
}

/*
int main()
{
    printf("result:%s\n",ft_itoa(-2147483648));
}
    */