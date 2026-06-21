#include "libft.h"

bool	ft_isspace(char a)
{
	if (a == ' ' || (a >= '\t' && a <= '\r'))
		return (true);
	return (false);
}
