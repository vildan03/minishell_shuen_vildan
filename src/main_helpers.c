
#include "../inc/executor.h"
#include "../inc/minishell.h"

static char	**free_partial_copy(char **copy, int count)
{
	while (count > 0)
		free(copy[--count]);
	free(copy);
	return (NULL);
}

static void	handle_sigint(int sig)
{
	(void)sig;
	g_exit_status = 130;
	if (write(1, "\n", 1) < 0)
		return ;
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
void	interactive_signals(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}
void	execution_signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
char	**copy_envp(char **envp)
{
	char	**copy;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		copy[i] = ft_strdup(envp[i]);
		if (!copy[i])
			return (free_partial_copy(copy, i));
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	init_shell(t_shell *shell, char **envp)
{
	shell->env = copy_envp(envp);
	shell->export = copy_envp(envp);
	shell->last_exit_status = 0;
	shell->token_list = NULL;
	shell->ast_root = NULL;
	if (!shell->env || !shell->export)
	{
		free_array(shell->env);
		free_array(shell->export);
		shell->env = NULL;
		shell->export = NULL;
		return (1);
	}
	return (0);
}
