
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	i = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
	{
		substring = malloc(sizeof(*s));
		if (!substring)
			return (NULL);
		substring[0] = '\0';
		return (substring);
	}
	else
		substring = malloc(sizeof(*s) * (len + 1));
	if (!substring)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		substring[i++] = s[start];
		start++;
	}
	substring[i] = '\0';
	return (substring);
}
