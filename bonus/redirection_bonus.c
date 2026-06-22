/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:51:36 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 11:58:11 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor_bonus.h"
#include "minishell_bonus.h"
#include "parser_bonus.h"

static int	open_redirection_fd(t_redir *redir, t_shell *shell) //
{
	if (redir->type == REDIR_OUT)
		return (open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644));
	if (redir->type == REDIR_APPEND)
		return (open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644));
	if (redir->type == REDIR_IN)
		return (open(redir->file, O_RDONLY));
	if (redir->type == REDIR_HEREDOC)
		return (process_heredoc(redir, shell));
	return (-1);
}

static int	get_target_fd(t_redir_type type) //
{
	if (type == REDIR_IN || type == REDIR_HEREDOC)
		return (STDIN_FILENO);
	return (STDOUT_FILENO);
}

static int	check_ambiguous(t_redir *redir, t_hd_fd *heredoc_fds)
{
	int	i;

	if (!redir->quoted && (!redir->file || redir->file[0] == '\0'
			|| ft_strchr(redir->file, ' ') || ft_strchr(redir->file, 2)))
	{
		ft_putstr_fd("minishell: ", 2);
		if (redir->file)
		{
			i = 0;
			while (redir->file[i])
			{
				if (redir->file[i] == 2)
					redir->file[i] = ' ';
				i++;
			}
			ft_putstr_fd(redir->file, 2);
		}
		ft_putendl_fd(": ambiguous redirect", 2);
		clear_heredoc_fds(heredoc_fds);
		return (1);
	}
	return (0);
}

static int	apply_one_redirection(t_redir *redir, t_hd_fd **heredoc_fds,
		t_shell *shell)
{
	int	fd;
	int	target_fd;

	if (redir->type == REDIR_HEREDOC)
		fd = next_heredoc_fd(heredoc_fds);
	else
	{
		if (check_ambiguous(redir, *heredoc_fds))
			return (-1);
		fd = open_redirection_fd(redir, shell);
	}
	if (fd == -1)
	{
		clear_heredoc_fds(*heredoc_fds);
		if (redir->type != REDIR_HEREDOC)
			print_errno_error(redir->file);
		return (-1);
	}
	target_fd = get_target_fd(redir->type);
	if (dup2(fd, target_fd) == -1)
		return (close(fd), clear_heredoc_fds(*heredoc_fds), perror("dup2"), -1);
	close(fd);
	return (0);
}

int	apply_redirections(t_redir *redir, t_shell *shell) //
{
	t_hd_fd	*heredoc_fds;

	heredoc_fds = NULL;
	if (collect_heredoc_fds(redir, &heredoc_fds, shell) != 0)
		return (-1);
	while (redir)
	{
		if (apply_one_redirection(redir, &heredoc_fds, shell) == -1)
			return (-1);
		redir = redir->next;
	}
	return (0);
}
