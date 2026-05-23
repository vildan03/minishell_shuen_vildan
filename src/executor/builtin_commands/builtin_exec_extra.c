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
int	exec_builtin_export(char **args, t_shell *shell)
{
	char *sep;
	char *key;
	int key_len;

	key_len = 0;
	if (args[1] && args[2])
		return (1);
	if (!args[1])
	{
		if (print_env(shell) == 1)
			return (1);
		return (0);
	}
	sep = ft_strchr(args[1], '=');
	if (!sep)
		return(1);
	key_len = sep - args[1];
	if (key_len == 0 || sep[1] == '\0')
		return (1);
	key = malloc(key_len + 1);
	if (!key)
		return (1);
	ft_strlcpy(key, args[1], key_len + 1);
	if (update_env_value(shell, key, sep + 1) == 1)
		return (free(key), 1);
	return (free(key),(0));
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

int	exec_builtin_exit(char **args, t_shell *shell)
{
	(void)args;
	(void)shell;
	return (0);
}

