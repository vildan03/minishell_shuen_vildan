
#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		s_length;
	char	*dup;

	s_length = ft_strlen(s);
	dup = malloc(sizeof(*s) * (s_length + 1));
	if (!dup)
		return (NULL);
	while (*s)
	{
		*dup = *s;
		dup++;
		s++;
	}
	*dup = '\0';
	return (dup - s_length);
}
