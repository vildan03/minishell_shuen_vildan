
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;
	char			*str;

	str = (char *)s;
	uc = (unsigned char)c;
	while (*str)
	{
		if (*str == uc % 256)
			return (str);
		str++;
	}
	if (*str == '\0' && uc == '\0')
		return (str);
	return (NULL);
}
