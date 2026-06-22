/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_fds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:52:06 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 10:52:07 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor_bonus.h"
#include "minishell_bonus.h"

static char	*get_tmp_filename(void)
{
	static int	counter = 0;
	char		*cnt_str;
	char		*filename;

	cnt_str = ft_itoa(counter++);
	if (!cnt_str)
		return (NULL);
	filename = ft_strjoin("/tmp/.minishell_hd_", cnt_str);
	free(cnt_str);
	return (filename);
}

int	create_heredoc_fd(t_redir *redir, t_shell *shell)
{
	int		write_fd;
	int		read_fd;
	char	*filename;

	filename = get_tmp_filename();
	if (!filename)
		return (-1);
	write_fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (write_fd == -1)
		return (free(filename), -1);
	if (fill_heredoc_pipe(write_fd, redir, shell) != 0)
	{
		close(write_fd);
		unlink(filename);
		free(filename);
		return (-1);
	}
	close(write_fd);
	read_fd = open(filename, O_RDONLY);
	unlink(filename);
	free(filename);
	return (read_fd);
}

void	clear_heredoc_fds(t_hd_fd *head)
{
	t_hd_fd	*next;

	while (head)
	{
		next = head->next;
		close(head->fd);
		free(head);
		head = next;
	}
}
