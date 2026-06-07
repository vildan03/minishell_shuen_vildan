#include "minishell.h"
#include "parser.h"
#include "executor.h"
#include <fcntl.h>

typedef struct s_hd_fd
{
	int				fd;
	struct s_hd_fd	*next;
}	t_hd_fd;

static int	open_redirection_fd(t_redir *redir)
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

static int	get_target_fd(t_redir_type type)
{
	if (type == REDIR_IN || type == REDIR_HEREDOC)
		return (STDIN_FILENO);
	return (STDOUT_FILENO);
}

static void	clear_heredoc_fds(t_hd_fd *head)
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

static int	collect_heredoc_fds(t_redir *redir, t_hd_fd **head)
{
	int	fd;

	while (redir)
	{
		if (redir->type == REDIR_HEREDOC)
		{
			fd = process_heredoc(redir);
			if (fd == -1 || append_heredoc_fd(head, fd) != 0)
				return (clear_heredoc_fds(*head), *head = NULL, 1);
		}
		redir = redir->next;
	}
	return (0);
}

static int	next_heredoc_fd(t_hd_fd **head)
{
	t_hd_fd	*current;
	int		fd;

	current = *head;
	fd = current->fd;
	*head = current->next;
	free(current);
	return (fd);
}

int	apply_redirections(t_redir *redir)
{
	int	fd;
	int	target_fd;
	t_hd_fd	*heredoc_fds;

	heredoc_fds = NULL;
	if (collect_heredoc_fds(redir, &heredoc_fds) != 0)
		return (-1);
	while (redir)
	{
		if (redir->type == REDIR_HEREDOC)
			fd = next_heredoc_fd(&heredoc_fds);
		else
			fd = open_redirection_fd(redir);
		if (fd == -1)
		{
			clear_heredoc_fds(heredoc_fds);
			if (redir->type != REDIR_HEREDOC)
				perror(redir->file);
			return (-1);
		}
		target_fd = get_target_fd(redir->type);
		if (dup2(fd, target_fd) == -1)
		{
			close(fd);
			clear_heredoc_fds(heredoc_fds);
			perror("dup2");
			return (-1);
		}
		close(fd);
		redir = redir->next;
	}
	return (0);
}
