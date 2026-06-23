/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:51:59 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 10:52:00 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"
#include <errno.h>

int	finish_heredoc(int status, char *line, t_hd_state *state)
{
	if (line)
		free(line);
	if (state->term_set)
		tcsetattr(STDIN_FILENO, TCSANOW, &state->old_term);
	sigaction(SIGINT, &state->old_sigint, NULL);
	sigaction(SIGQUIT, &state->old_sigquit, NULL);
	return (status);
}

void	init_heredoc_state(t_hd_state *state, void (*sigint_handler)(int))
{
	struct sigaction	new_action;
	struct termios		new_term;

	new_action.sa_handler = sigint_handler;
	sigemptyset(&new_action.sa_mask);
	new_action.sa_flags = 0;
	sigaction(SIGINT, &new_action, &state->old_sigint);
	new_action.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &new_action, &state->old_sigquit);
	state->term_set = 0;
	if (isatty(STDIN_FILENO)
		&& tcgetattr(STDIN_FILENO, &state->old_term) == 0)
	{
		new_term = state->old_term;
		new_term.c_lflag &= ~ECHOCTL;
		if (tcsetattr(STDIN_FILENO, TCSANOW, &new_term) == 0)
			state->term_set = 1;
	}
}

static char	*grow_buffer(char *buf, size_t *capacity, size_t len)
{
	char	*new_buf;

	*capacity *= 2;
	new_buf = malloc(*capacity);
	if (!new_buf)
	{
		free(buf);
		return (NULL);
	}
	ft_memcpy(new_buf, buf, len);
	free(buf);
	return (new_buf);
}

static int	read_char(int fd, char *c)
{
	ssize_t	bytes;

	if (g_exit_status == 130)
		return (-1);
	bytes = read(fd, c, 1);
	if (bytes == -1 && errno == EINTR)
		return (read_char(fd, c));
	return ((int)bytes);
}

char	*read_line_from_fd(int fd)
{
	char	*buf;
	size_t	cap;
	size_t	len;
	char	c;

	cap = 128;
	buf = malloc(cap);
	if (!buf)
		return (NULL);
	len = 0;
	c = '\0';
	while (read_char(fd, &c) > 0 && c != '\n')
	{
		if (len + 1 >= cap)
		{
			buf = grow_buffer(buf, &cap, len);
			if (!buf)
				return (NULL);
		}
		buf[len++] = c;
	}
	if (g_exit_status == 130 || (len == 0 && c != '\n'))
		return (free(buf), NULL);
	return (buf[len] = '\0', buf);
}
