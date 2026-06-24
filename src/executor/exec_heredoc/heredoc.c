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

#include "executor.h"
#include "minishell.h"

static void	handle_heredoc_sigint(int sig)
{
	int	r_val;

	(void)sig;
	g_exit_status = 130;
	r_val = write(2, "^C\n", 3);
	(void)r_val;
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

static int	process_heredoc_input(int write_fd, t_redir *redir, t_shell *shell,
		t_hd_state *state)
{
	char	*line;

	line = get_heredoc_line();
	while (line)
	{
		if (g_exit_status == 130)
			return (finish_heredoc(130, line, state));
		if (ft_strncmp(line, redir->file, ft_strlen(redir->file) + 1) == 0)
			return (finish_heredoc(0, line, state));
		if (handle_heredoc_line(write_fd, line, redir, shell) != 0)
			return (finish_heredoc(1, line, state));
		free(line);
		line = get_heredoc_line();
	}
	if (g_exit_status == 130)
		return (finish_heredoc(130, NULL, state));
	print_heredoc_warning(redir->file);
	return (finish_heredoc(0, NULL, state));
}

int	fill_heredoc_pipe(int write_fd, t_redir *redir, t_shell *shell)
{
	t_hd_state	state;

	init_heredoc_state(&state, handle_heredoc_sigint);
	return (process_heredoc_input(write_fd, redir, shell, &state));
}
