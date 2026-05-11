/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:51:24 by vikaradu          #+#    #+#             */
/*   Updated: 2025/11/20 18:51:26 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <string.h>
// alway null terminate dest_len >= size
// return total len
// If size <= dstlen: return size + srclen, and do not modify dst.
// size is the maximum size of the dest after the concatenate,
// we can have at th end;

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	j;
	size_t	dest_len;
	size_t	src_len;
	size_t	total_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	total_len = dest_len + src_len;
	if (size <= dest_len)
		return (size + src_len);
	if (dest_len < size)
	{
		j = 0;
		while (j < size - dest_len - 1 && src[j])
		{
			dest[dest_len + j] = src[j];
			++j;
		}
		dest[dest_len + j] = '\0';
	}
	return (total_len);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char s1[10];
    char s2[10];

    // size = 0
    strcpy(s1, "ab");
    strcpy(s2, "ab");
    printf("mine:%ld\n", ft_strlcat(s1, "qrs", 0));
    printf("real:%ld\n", strlcat(s2, "qrs", 0));

    // size = 1
    strcpy(s1, "ab");
    strcpy(s2, "ab");
    printf("mine:%ld\n", ft_strlcat(s1, "qrs", 1));
    printf("real:%ld\n", strlcat(s2, "qrs", 1));

    // size = 3
    strcpy(s1, "ab");
    strcpy(s2, "ab");
    printf("mine:%ld\n", ft_strlcat(s1, "qrs", 3));
    printf("real:%ld\n", strlcat(s2, "qrs", 3));

    // size = 6
    strcpy(s1, "ab");
    strcpy(s2, "ab");
    printf("mine:%ld\n", ft_strlcat(s1, "qrs", 6));
    printf("real:%ld\n", strlcat(s2, "qrs", 6));

    // size = 7
    strcpy(s1, "ab");
    strcpy(s2, "ab");
    printf("mine:%ld\n", ft_strlcat(s1, "qrs", 7));
    printf("real:%ld\n", strlcat(s2, "qrs", 7));

    return 0;
}
*/