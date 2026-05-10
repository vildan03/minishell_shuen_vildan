
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*location;
	int				found;
	unsigned char	uc;

	found = 0;
	uc = (unsigned char)c;
	while (*s)
	{
		if (*s == uc % 256)
		{
			location = (char *)s;
			found = 1;
		}
		s++;
	}
	if (*s == '\0' && uc == '\0')
		return ((char *)s);
	if (found == 0)
		return (NULL);
	return (location);
}
