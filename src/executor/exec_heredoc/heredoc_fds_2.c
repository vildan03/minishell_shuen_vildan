/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_fds_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:52:04 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 10:52:05 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "minishell.h"

static int	append_heredoc_fd(t_hd_fd **head, int fd)
{
	t_hd_fd	*new_node;
	t_hd_fd	*current;

	new_node = malloc(sizeof(t_hd_fd));
	if (!new_node)
		return (close(fd), 1);
	new_node->fd = fd;
	new_node->next = NULL;
	if (!*head)
		return (*head = new_node, 0);
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new_node;
	return (0);
}

int	next_heredoc_fd(t_hd_fd **head)
{
	t_hd_fd	*current;
	int		fd;

	current = *head;
	fd = current->fd;
	*head = current->next;
	free(current);
	return (fd);
}

int	collect_heredoc_fds(t_redir *redir, t_hd_fd **head, t_shell *shell)
{
	int	fd;

	while (redir)
	{
		if (redir->type == REDIR_HEREDOC)
		{
			fd = process_heredoc(redir, shell);
			if (fd == -1 || append_heredoc_fd(head, fd) != 0)
				return (clear_heredoc_fds(*head), *head = NULL, 1);
		}
		redir = redir->next;
	}
	return (0);
}
