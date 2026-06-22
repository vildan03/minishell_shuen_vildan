#include "executor.h"
#include "minishell.h"

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
