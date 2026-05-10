
#include "libft.h"
#include <stdint.h>
#include <stdlib.h>

void	*ft_calloc(size_t n, size_t size)
{
	size_t	array_size;
	char	*array_location;

	if ((size != 0 && n != 0) && size > (SIZE_MAX / n))
		return (NULL);
	array_size = n * size;
	array_location = malloc(array_size);
	if (!array_location)
		return (NULL);
	ft_memset(array_location, 0, array_size);
	return (array_location);
}
