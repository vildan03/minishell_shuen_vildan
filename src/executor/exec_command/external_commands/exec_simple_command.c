/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:51:34 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 10:51:35 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "expander.h"
#include "minishell.h"

int	get_child_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGQUIT)
			ft_putendl_fd("Quit (core dumped)", 2);
		return (128 + WTERMSIG(status));
	}
	return (1);
}

static void	cleanup_external_child(t_shell *shell, char *path, int status)
{
	free(path);
	cleanup_process_state(shell, shell->ast_root, shell->token_list);
	exit(status);
}

void	exec_external_child(t_ast_node *node, t_shell *shell)
{
	char	*path;
	int		status;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	free(shell->current_input);
	shell->current_input = NULL;
	if (apply_redirections(node->redir, shell) == -1)
		cleanup_external_child(shell, NULL, 1);
	path = find_command_path(node->args[0], shell->env);
	status = validate_exec_path(node->args[0], path);
	if (status != 0)
		cleanup_external_child(shell, path, status);
	execve(path, node->args, shell->env);
	perror(node->args[0]);
	cleanup_external_child(shell, path, 126);
}

static int	wait_simple_command(pid_t pid)
{
	int	status;

	if (waitpid(pid, &status, 0) == -1)
		return (perror("waitpid"), 1);
	return (get_child_status(status));
}

int	exec_simple_command(t_ast_node *node, t_shell *shell)
{
	pid_t	pid;

	if (!node || !node->args || !node->args[0])
		return (0);
	if (ft_strncmp(node->args[0], "!", 2) == 0 && node->args[1] == NULL)
		return (shell->last_exit_status = 1, 1);
	pid = fork();
	if (pid == -1)
		return (perror("fork"), 1);
	if (pid == 0)
		exec_external_child(node, shell);
	return (wait_simple_command(pid));
}
