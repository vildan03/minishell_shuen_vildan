#include "../../../inc/minishell.h"
#include "../../../inc/executor.h"

static int print_env(t_shell *shell)
{
	int	i;

	if (!shell || !shell->env)
		return (1);
	i = 0;
	while (shell->env[i])
	{
		ft_putendl_fd(shell->env[i], 1);
		i++;
	}
	return (0);
}

int	exec_builtin_env(char **args, t_shell *shell)
{
	int	i;

	if (!shell || !shell->env)
		return (1);
	if (args[1])
		return (1);
	i = 0;
	while (shell->env[i])
	{
		ft_putendl_fd(shell->env[i], 1);
		i++;
	}
	return (0);
}

