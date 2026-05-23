#include "../../../inc/minishell.h"
#include "../../../inc/executor.h"

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strncmp(cmd, "pwd", 4) == 0)
		return (1);
	if (ft_strncmp(cmd, "cd", 3) == 0)
		return (1);
	if (ft_strncmp(cmd, "echo", 5) == 0)
		return (1);
	if (ft_strncmp(cmd, "export", 7) == 0)
		return (1);
	if (ft_strncmp(cmd, "unset", 6) == 0)
		return (1);
	if (ft_strncmp(cmd, "env", 4) == 0)
		return (1);
	if (ft_strncmp(cmd, "exit", 5) == 0)
		return (1);
	return (0);
}
int	is_n_flag(char *arg)
{
	int	i;

	if (!arg || arg[0] != '-' || arg[1] != 'n')
		return (0);
	i = 2;
	while (arg[i] == 'n')
		i++;
	if (arg[i] != '\0')
		return (0);
	return (1);
}
char	*get_cd_target(char **args, t_shell *shell)
{
	if (!shell || !shell->env)
		return (NULL);
	if (args[1] && args[2])
		return (NULL);
	if (!args[1])
		return (get_env_value(shell->env, "HOME"));
	if (ft_strncmp(args[1], "-", 2) == 0)
		return (get_env_value(shell->env, "OLDPWD"));
	return (args[1]);
}

