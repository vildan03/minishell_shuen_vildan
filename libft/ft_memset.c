/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:08:09 by vikaradu          #+#    #+#             */
/*   Updated: 2025/11/20 18:08:10 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*p;

	p = (unsigned char *)ptr;
	while (num > 0)
	{
		p[num - 1] = (unsigned char)value;
		num--;
	}
	return (ptr);
}

/*
void	main(void)
{
int		ptr[6] = {0,2,4,1,1,1};

ft_memset(ptr,0,sizeof(ptr));
for(int i = 0; i < 6; ++i)
printf("%d",ptr[i]);
}
*/