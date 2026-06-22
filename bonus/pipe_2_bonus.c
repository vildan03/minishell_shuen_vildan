/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:52:54 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 10:52:55 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "executor_bonus.h"
# include "minishell_bonus.h"

static void	exit_pipe_error(int fd[2], t_shell *shell)
{
	perror("dup2");
	close(fd[0]);
	close(fd[1]);
	cleanup_shell(shell);
	exit(1);
}

void	setup_pipe_child_2(int fd[2], t_shell *shell, int is_left)
{
	if (is_left)
	{
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			exit_pipe_error(fd, shell);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			exit_pipe_error(fd, shell);
		close(fd[0]);
	}
}
