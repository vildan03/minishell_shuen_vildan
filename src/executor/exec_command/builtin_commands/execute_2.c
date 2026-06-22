/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:49:39 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 10:49:40 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"

static int	restore_builtin_fds(int saved_stdout, int saved_stdin, int status)
{
	int	restore_failed;

	restore_failed = 0;
	if (dup2(saved_stdout, STDOUT_FILENO) == -1)
		restore_failed = 1;
	if (dup2(saved_stdin, STDIN_FILENO) == -1)
		restore_failed = 1;
	close(saved_stdout);
	close(saved_stdin);
	if (restore_failed)
		return (perror("dup2"), 1);
	return (status);
}

int	exec_builtin_with_redir(t_ast_node *node, t_shell *shell)
{
	int	saved_stdout;
	int	saved_stdin;
	int	status;

	saved_stdout = dup(STDOUT_FILENO);
	saved_stdin = dup(STDIN_FILENO);
	if (saved_stdout == -1 || saved_stdin == -1)
	{
		close(saved_stdout);
		close(saved_stdin);
		return (perror("dup"), 1);
	}
	if (apply_redirections(node->redir, shell) == -1)
		return (restore_builtin_fds(saved_stdout, saved_stdin, 1));
	if (ft_strncmp(node->args[0], "exit", 5) == 0)
		return (exec_builtin_exit(node->args, shell, saved_stdout,
				saved_stdin));
	status = exec_builtin(node, shell);
	if (status != 0 && !isatty(STDIN_FILENO) && !shell->in_list
		&& (ft_strncmp(node->args[0], "export", 7) == 0
			|| ft_strncmp(node->args[0], "unset", 6) == 0))
	{
		status = restore_builtin_fds(saved_stdout, saved_stdin, status);
		cleanup_shell(shell);
		exit(status);
	}
	return (restore_builtin_fds(saved_stdout, saved_stdin, status));
}
