#include "executor.h"
#include "minishell.h"
#include "parser.h"

static int	open_redirection_fd(t_redir *redir) //
{
	if (redir->type == REDIR_OUT)
		return (open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644));
	if (redir->type == REDIR_APPEND)
		return (open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644));
	if (redir->type == REDIR_IN)
		return (open(redir->file, O_RDONLY));
	if (redir->type == REDIR_HEREDOC)
		return (process_heredoc(redir));
	return (-1);
}

static int	get_target_fd(t_redir_type type) //
{
	if (type == REDIR_IN || type == REDIR_HEREDOC)
		return (STDIN_FILENO);
	return (STDOUT_FILENO);
}

static int	apply_one_redirection(t_redir *redir, t_hd_fd **heredoc_fds) //
{
	int fd;
	int target_fd;

	if (redir->type == REDIR_HEREDOC)
		fd = next_heredoc_fd(heredoc_fds);
	else
		fd = open_redirection_fd(redir);
	if (fd == -1)
	{
		clear_heredoc_fds(*heredoc_fds);
		if (redir->type != REDIR_HEREDOC)
			perror(redir->file);
		return (-1);
	}
	target_fd = get_target_fd(redir->type);
	if (dup2(fd, target_fd) == -1)
		return (close(fd), clear_heredoc_fds(*heredoc_fds), perror("dup2"), -1);
	close(fd);
	return (0);
}

int	apply_redirections(t_redir *redir) //
{
	t_hd_fd *heredoc_fds;

	heredoc_fds = NULL;
	if (collect_heredoc_fds(redir, &heredoc_fds) != 0)
		return (-1);
	while (redir)
	{
		if (apply_one_redirection(redir, &heredoc_fds) == -1)
			return (-1);
		redir = redir->next;
	}
	return (0);
}
