
#include "libft.h"
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (n != 0)
	{
		str[i] = c;
		i++;
		n--;
	}
	return (str);
}
