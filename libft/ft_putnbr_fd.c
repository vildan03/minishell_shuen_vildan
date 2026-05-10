
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int	count_int_length(long n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static int	position(int count)
{
	int	position;

	position = 1;
	while (count != 0)
	{
		position *= 10;
		count--;
	}
	return (position);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	n_plus;
	char	a;
	int		count;

	n_plus = (long)n;
	if (n_plus == 0)
		write(fd, "0", 1);
	if (n_plus < 0)
	{
		n_plus *= -1;
		write(fd, "-", 1);
	}
	count = count_int_length(n_plus);
	while (count > 0)
	{
		if (count > 1)
		{
			a = n_plus / position(count - 1) + '0';
			n_plus %= position(count - 1);
		}
		else
			a = n_plus + '0';
		write(fd, &a, 1);
		count--;
	}
}
