#include "../../inc/executor.h"
#include "../../inc/minishell.h"

volatile sig_atomic_t	g_exit_status = 0;

bool	is_whitespaces_only(char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (!ft_isspace(input[i]))
			return (false);
		i++;
	}
	return (true);
}

static char	*read_shell_input(int interactive)
{
	if (interactive)
	{
		rl_outstream = stderr;
		return (readline("minishell$ "));
	}
	return (read_noninteractive_line());
}

static int	handle_shell_input(t_shell *shell, char *input, int interactive)
{
	if (g_exit_status)
	{
		shell->last_exit_status = g_exit_status;
		g_exit_status = 0;
	}
	if (!input)
	{
		if (interactive)
			ft_putendl_fd("exit", 2);
		return (0);
	}
	process_command(shell, input, interactive);
	free(input);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	char	*input;
	int		interactive;

	(void)argc;
	(void)argv;
	if (init_shell(&shell, envp))
		return (1);
	interactive = isatty(STDIN_FILENO) && isatty(STDERR_FILENO);
	while (1)
	{
		interactive_signals();
		input = read_shell_input(interactive);
		if (!handle_shell_input(&shell, input, interactive))
			break ;
	}
	free_array(shell.env);
	free_array(shell.export);
	return (shell.last_exit_status);
}
