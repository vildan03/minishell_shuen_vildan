#include "../../inc/minishell.h"
#include "../../inc/executor.h"
#include <stdio.h>
static int	env_count(char **envp)
{
	int i;

	i = 0;
	while (envp && envp[i])
		i++;
	return (i);
}

static char	**copy_envp(char **envp)
{
	char	**copy;
	int		count;
	int		i;

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
			while (i-- > 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argc;
	argv[0] = "export";
	argv[1] = "K=V";
	argv[2] = NULL;
	shell.env = copy_envp(envp);
	if (!shell.env)
		return (1);
	shell.last_exit_status = 0;
	if (exec_builtin_export(argv, &shell))
		return (printf("fail\n"),1);
	return (printf("succes\n"), 0);
}