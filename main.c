#include "inc/minishell.h"
#include "inc/executor.h"

static int	env_count(char **envp)
{
	int	i;

	i = 0;
	while (envp && envp[i])
		i++;
	return (i);
}

static void	free_env_copy(char **copy, int used)
{
	int	i;

	i = 0;
	while (i < used)
	{
		free(copy[i]);
		i++;
	}
	free(copy);
}

static char	**copy_envp(char **envp)
{
	char	**copy;
	int		i;
	int		count;

	count = env_count(envp);
	copy = malloc(sizeof(char *) * (count + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < count)
	{
		copy[i] = ft_strdup(envp[i]);
		if (!copy[i])
		{
			free_env_copy(copy, i);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argc;
	(void)argv;
	shell.env = copy_envp(envp);
	if (!shell.env)
		return (1);
	shell.last_exit_status = 0;
	return (0);
}
