/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:06:50 by vikaradu          #+#    #+#             */
/*   Updated: 2025/11/20 18:06:51 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>

void	ft_bzero(void *ptr, size_t num)
{
	unsigned char	*p;

	p = (unsigned char *)ptr;
	while (num > 0)
	{
		p[num - 1] = 0;
		num--;
	}
}
/*
void	main(void)
{
int		ptr[7] = {0,2,4,1,1,1,2};
ft_bzero(ptr,sizeof(ptr));
for(int i = 0; i < 7; ++i)
printf("%d",ptr[i]);
}*/