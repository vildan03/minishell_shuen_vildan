/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:08:38 by vikaradu          #+#    #+#             */
/*   Updated: 2025/11/20 18:08:39 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

// static int	str_len(char *str)
// {
// 	int	i;
// 	i = 0;
// 	while (str[i])
// 	{
// 		++i;
// 	}
// 	return (i);
// }

void	str_cpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
}

char	*ft_strdup(char *src)
{
	size_t	src_len;
	char	*duplicate;

	src_len = ft_strlen(src);
	duplicate = malloc(src_len * sizeof(char) + 1);
	if (!duplicate)
		return (NULL);
	str_cpy(duplicate, src);
	return (duplicate);
}

/*
void	write_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		++i;
	}
}

int	main(void)
{
	char	src[] = "hello";
	int		src_len;
	char	*dup;

	src_len = str_len(src);
	dup = malloc(src_len * sizeof(char) + 1);
	dup = ft_strdup(src);
	write_str(dup);
}
*/