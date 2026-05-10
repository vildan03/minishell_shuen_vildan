
#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	(void)write(fd, s, ft_strlen(s));
}
