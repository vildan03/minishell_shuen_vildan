/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kerlee <kerlee@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 17:07:02 by kerlee            #+#    #+#             */
/*   Updated: 2026/06/22 17:07:17 by kerlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "expander.h"
#include "minishell.h"

int	exec_and(t_ast_node *node, t_shell *shell)
{
	int	left_status;

	if (!node || !node->left || !node->right)
		return (1);
	shell->in_list++;
	left_status = exec_ast(node->left, shell);
	shell->last_exit_status = left_status;
	if (left_status == 0)
	{
		left_status = exec_ast(node->right, shell);
		shell->in_list--;
		return (left_status);
	}
	shell->in_list--;
	return (left_status);
}

int	exec_or(t_ast_node *node, t_shell *shell)
{
	int	left_status;

	if (!node || !node->left || !node->right)
		return (1);
	shell->in_list++;
	left_status = exec_ast(node->left, shell);
	shell->last_exit_status = left_status;
	if (left_status != 0)
	{
		left_status = exec_ast(node->right, shell);
		shell->in_list--;
		return (left_status);
	}
	shell->in_list--;
	return (left_status);
}

int	exec_subshell(t_ast_node *node, t_shell *shell)
{
	pid_t	pid;
	int		status;
	int		exit_code;

	if (!node || !node->left)
		return (0);
	pid = fork();
	if (pid == -1)
		return (perror("minishell: subshell fork"), 1);
	if (pid == 0)
	{
		if (node->redir && apply_redirections(node->redir, shell) != 0)
		{
			cleanup_shell(shell);
			exit(1);
		}
		exit_code = exec_ast(node->left, shell);
		cleanup_shell(shell);
		exit(exit_code);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
