/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:06:53 by vikaradu          #+#    #+#             */
/*   Updated: 2025/11/24 13:36:06 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (nmemb == 0 || size == 0)
	{
		result = malloc(0);
		if (!result)
			return (NULL);
		return (result);
	}
	result = malloc(nmemb * size);
	if (!result)
		return (NULL);
	ft_bzero (result, (nmemb * size));
	return (result);
}
