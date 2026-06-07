#include "../../../inc/minishell.h"
#include "../../../inc/executor.h"

static int	is_delimiter(char *line, char *delimiter)
{
	if (!line || !delimiter)
		return (0);
	return (ft_strncmp(line, delimiter, ft_strlen(delimiter) + 1) == 0);
}

static int	write_heredoc_line(int fd, char *line)
{
	if (write(fd, line, ft_strlen(line)) == -1)
		return (perror("write"), 1);
	if (write(fd, "\n", 1) == -1)
		return (perror("write"), 1);
	return (0);
}

static int	fill_heredoc_pipe(int write_fd, char *delimiter)
{
	char	*line;

	line = readline("> ");
	while (line)
	{
		if (is_delimiter(line, delimiter))
			return (free(line), 0);
		if (write_heredoc_line(write_fd, line) != 0)
			return (free(line), 1);
		free(line);
		line = readline("> ");
	}
	return (0);
}

static int	create_heredoc_fd(char *delimiter)
{
	int	fd[2];

	if (pipe(fd) == -1)
		return (perror("pipe"), -1);
	if (fill_heredoc_pipe(fd[1], delimiter) != 0)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	close(fd[1]);
	return (fd[0]);
}

int	has_heredoc(t_redir *redir)
{
	while (redir)
	{
		if (redir->type == REDIR_HEREDOC)
			return (1);
		redir = redir->next;
	}
	return (0);
}

int	process_heredoc(t_redir *redir)
{
	if (!redir || redir->type != REDIR_HEREDOC)
		return (-1);
	return (create_heredoc_fd(redir->file));
}
