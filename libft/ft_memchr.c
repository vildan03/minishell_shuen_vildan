
#include "libft.h"
#include <stddef.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*str;
	unsigned char	uc;

	str = (char *)s;
	uc = (unsigned char)c;
	while (n != 0)
	{
		if ((unsigned char)*str == uc % 256)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}
