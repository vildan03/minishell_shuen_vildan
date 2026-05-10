
#include "libft.h"
#include <stddef.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (n != 0 && *us1 && *us2)
	{
		if (*us1 > *us2)
			return (1);
		if (*us1 < *us2)
			return (-1);
		us1++;
		us2++;
		n--;
	}
	if (*us1 && n != 0)
		return (1);
	if (*us2 && n != 0)
		return (-1);
	return (0);
}
