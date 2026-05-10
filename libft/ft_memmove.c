
#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destination;
	const char	*source;

	if (dest == NULL && src == NULL)
		return (NULL);
	destination = (char *)dest;
	source = (const char *)src;
	if (n == 0)
		return (dest);
	if ((destination > source) && (destination < source + n))
	{
		destination += n - 1;
		source += n - 1;
		while (n--)
			*destination-- = *source--;
	}
	else
	{
		while (n != 0)
		{
			*destination++ = *source++;
			n--;
		}
	}
	return (dest);
}
