#include "minishell.h"
#include "parser.h"
#include <fcntl.h>

int	apply_redirections(t_redir *redir)
{
	int	fd;
	int	target_fd;

	while (redir)
	{
		fd = -1;
		if (redir->type == REDIR_OUT)
			fd = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (redir->type == REDIR_APPEND)
			fd = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else if (redir->type == REDIR_IN)
			fd = open(redir->file, O_RDONLY);
		if (fd == -1)
		{
			perror(redir->file);
			return -1;
		}
		target_fd = STDOUT_FILENO;
		if (redir->type == REDIR_IN)
			target_fd = STDIN_FILENO;
		dup2(fd, target_fd);
		close(fd);
		redir = redir->next;
	}
	return 0;
}
