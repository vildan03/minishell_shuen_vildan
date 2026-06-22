/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:53:31 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 13:32:49 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "executor_bonus.h"
# include "minishell_bonus.h"

char	**free_partial_copy(char **copy, int count)
{
	while (count > 0)
		free(copy[--count]);
	free(copy);
	return (NULL);
}

static void	handle_sigint(int sig)
{
	int	return_val;

	(void)sig;
	g_exit_status = 130;
	return_val = write(2, "\n", 1);
	(void)return_val;
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

int	init_shell(t_shell *shell, char **envp)
{
	shell->env = copy_envp(envp);
	shell->export = copy_envp(envp);
	shell->current_input = NULL;
	shell->last_exit_status = 0;
	shell->in_list = 0;
	shell->token_list = NULL;
	shell->ast_root = NULL;
	if (!shell->env || !shell->export)
	{
		free_array(shell->env);
		free_array(shell->export);
		shell->env = NULL;
		shell->export = NULL;
		shell->current_input = NULL;
		return (1);
	}
	return (0);
}
