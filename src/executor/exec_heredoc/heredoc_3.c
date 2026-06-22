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
	{
		if (g_exit_status == 130)
			return (-1);
		return (read_char(fd, c));
	}
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
