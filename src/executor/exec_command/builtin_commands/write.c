#include "../../../../inc/executor.h"
#include "../../../../inc/minishell.h"

int	print_env_error(char *arg)
{
	ft_putstr_fd("minishell: env: '", 2);
	ft_putstr_fd(arg, 2);
	ft_putendl_fd("': No such file or directory", 2);
	return (127);
}

int	write_builtin_char(char c, char *name)
{
	if (write(STDOUT_FILENO, &c, 1) == -1)
		return (perror(name), 1);
	return (0);
}

int	write_builtin_str(char *str, char *name)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (write(STDOUT_FILENO, &str[i], 1) == -1)
			return (perror(name), 1);
		i++;
	}
	return (0);
}
