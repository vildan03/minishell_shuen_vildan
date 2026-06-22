/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:52:51 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 09:06:54 by kerlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor_bonus.h"
#include "minishell_bonus.h"
#include <errno.h>

static void	handle_heredoc_sigint(int sig)
{
	(void)sig;
	g_exit_status = 130;
	close(STDIN_FILENO);
}

static int	finish_heredoc(int status, char *line, void (*old_sigint)(int),
		void (*old_sigquit)(int))
{
	if (line)
		free(line);
	signal(SIGINT, old_sigint);
	signal(SIGQUIT, old_sigquit);
	return (status);
}

static void	write_prompt(void)
{
	int	r_val;

	r_val = write(2, "> ", 2);
	(void)r_val;
}

static char	*get_heredoc_line(void)
{
	if (isatty(STDIN_FILENO))
		write_prompt();
	return (read_line_from_fd(STDIN_FILENO));
}

int	fill_heredoc_pipe(int write_fd, t_redir *redir, t_shell *shell)
{
	char	*line;
	void	(*old_sigint)(int);
	void	(*old_sigquit)(int);

	old_sigint = signal(SIGINT, handle_heredoc_sigint);
	old_sigquit = signal(SIGQUIT, SIG_IGN);
	line = get_heredoc_line();
	while (line)
	{
		if (g_exit_status == 130)
			return (write_newline(), finish_heredoc(130, line, old_sigint,
					old_sigquit));
		if (ft_strncmp(line, redir->file, ft_strlen(redir->file) + 1) == 0)
			return (finish_heredoc(0, line, old_sigint, old_sigquit));
		if (handle_heredoc_line(write_fd, line, redir, shell) != 0)
			return (finish_heredoc(1, line, old_sigint, old_sigquit));
		free(line);
		line = get_heredoc_line();
	}
	if (g_exit_status == 130)
		return (write_newline(), finish_heredoc(130, NULL, old_sigint,
				old_sigquit));
	print_heredoc_warning(redir->file);
	return (finish_heredoc(0, NULL, old_sigint, old_sigquit));
}
