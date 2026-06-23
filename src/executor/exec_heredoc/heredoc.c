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
#include <errno.h>
#include <termios.h>

typedef struct s_hd_state
{
	struct termios	old_term;
	int				term_set;
	void			(*old_sigint)(int);
	void			(*old_sigquit)(int);
}	t_hd_state;

static void	handle_heredoc_sigint(int sig)
{
	int	r_val;

	(void)sig;
	g_exit_status = 130;
	r_val = write(2, "^C\n", 3);
	(void)r_val;
	close(STDIN_FILENO);
}

static int	finish_heredoc(int status, char *line, t_hd_state *state)
{
	if (line)
		free(line);
	if (state->term_set)
		tcsetattr(STDIN_FILENO, TCSANOW, &state->old_term);
	signal(SIGINT, state->old_sigint);
	signal(SIGQUIT, state->old_sigquit);
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
	char			*line;
	struct termios	new_term;
	t_hd_state		state;

	state.old_sigint = signal(SIGINT, handle_heredoc_sigint);
	state.old_sigquit = signal(SIGQUIT, SIG_IGN);
	state.term_set = 0;
	if (isatty(STDIN_FILENO) && tcgetattr(STDIN_FILENO, &state.old_term) == 0)
	{
		new_term = state.old_term;
		new_term.c_lflag &= ~ECHOCTL;
		if (tcsetattr(STDIN_FILENO, TCSANOW, &new_term) == 0)
			state.term_set = 1;
	}
	line = get_heredoc_line();
	while (line)
	{
		if (g_exit_status == 130)
			return (finish_heredoc(130, line, &state));
		if (ft_strncmp(line, redir->file, ft_strlen(redir->file) + 1) == 0)
			return (finish_heredoc(0, line, &state));
		if (handle_heredoc_line(write_fd, line, redir, shell) != 0)
			return (finish_heredoc(1, line, &state));
		free(line);
		line = get_heredoc_line();
	}
	if (g_exit_status == 130)
		return (finish_heredoc(130, NULL, &state));
	print_heredoc_warning(redir->file);
	return (finish_heredoc(0, NULL, &state));
}
