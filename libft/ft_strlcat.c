
#include "libft.h"
#include <stddef.h>
#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;

	i = 0;
	if (ft_strlen(dest) >= destsize)
		return (destsize + ft_strlen(src));
	while (dest[i] != '\0')
		i++;
	while (destsize - 1 > i && *src != '\0')
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (ft_strlen(dest) + ft_strlen(src));
}
