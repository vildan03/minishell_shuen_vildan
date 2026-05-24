
#include "../../../../inc/minishell.h"
#include "../../../../inc/executor.h"
static int	is_numeric(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	print_numeric_error(char *arg)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putendl_fd(": numeric argument required", 2);
}

int	exec_builtin_exit(char **args, t_shell *shell)
{
	int	exit_code;

	ft_putendl_fd("exit", 1);
	if (!args[1])
	{
		cleanup_shell(shell);
		exit(shell->last_exit_status);
	}
	if (!is_numeric(args[1]))
	{
		print_numeric_error(args[1]);
		cleanup_shell(shell);
		exit(2);
	}
	if (args[2])
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		shell->last_exit_status = 1;
		return (1);
	}
	exit_code = ft_atoi(args[1]) % 256;
	if (exit_code < 0)
		exit_code += 256;
	cleanup_shell(shell);
	exit(exit_code);
}
