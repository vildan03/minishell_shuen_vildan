#include "../../../inc/executor.h"
#include "../../../inc/minishell.h"

static int	write_heredoc_line(int fd, char *line)
{
	if (write(fd, line, ft_strlen(line)) == -1)
		return (perror("write"), 1);
	if (write(fd, "\n", 1) == -1)
		return (perror("write"), 1);
	return (0);
}

static int	is_delimiter(char *line, char *delimiter)
{
	if (!line || !delimiter)
		return (0);
	return (ft_strncmp(line, delimiter, ft_strlen(delimiter) + 1) == 0);
}

static int	finish_heredoc(int status, char *line, void (*old_quit)(int))
{
	if (line)
		free(line);
	signal(SIGQUIT, old_quit);
	return (status);
}

int	fill_heredoc_pipe(int write_fd, char *delimiter)
{
	char	*line;
	void	(*old_quit)(int);

	old_quit = signal(SIGQUIT, SIG_IGN);
	line = readline("> ");
	while (line)
	{
		if (is_delimiter(line, delimiter))
			return (finish_heredoc(0, line, old_quit));
		if (write_heredoc_line(write_fd, line) != 0)
			return (finish_heredoc(1, line, old_quit));
		free(line);
		line = readline("> ");
	}
	return (finish_heredoc(0, NULL, old_quit));
}

int	process_heredoc(t_redir *redir)
{
	if (!redir || redir->type != REDIR_HEREDOC)
		return (-1);
	return (create_heredoc_fd(redir->file));
}
