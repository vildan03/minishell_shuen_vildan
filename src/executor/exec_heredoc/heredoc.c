#include "executor.h"
#include "minishell.h"

static int	write_heredoc_line(int fd, char *line)
{
	if (write(fd, line, ft_strlen(line)) == -1)
		return (perror("write"), 1);
	if (write(fd, "\n", 1) == -1)
		return (perror("write"), 1);
	return (0);
}

static int	finish_heredoc(int status, char *line, void (*old_quit)(int))
{
	if (line)
		free(line);
	signal(SIGQUIT, old_quit);
	return (status);
}

static void	print_heredoc_warning(char *delimiter)
{
	ft_putstr_fd("minishell: warning: here-document delimited by ", 2);
	ft_putstr_fd("end-of-file (wanted `", 2);
	ft_putstr_fd(delimiter, 2);
	ft_putendl_fd("')", 2);
}

static int	handle_heredoc_line(int write_fd, char *line, t_redir *redir,
		t_shell *shell)
{
	char	*content;

	content = line;
	if (!redir->quoted)
		content = expand_heredoc_line(line, shell->env, shell->last_exit_status);
	if (!content)
		return (1);
	if (write_heredoc_line(write_fd, content) != 0)
	{
		if (content != line)
			free(content);
		return (1);
	}
	if (content != line)
		free(content);
	return (0);
}

int	fill_heredoc_pipe(int write_fd, t_redir *redir, t_shell *shell)
{
	char	*line;
	void	(*old_quit)(int);

	old_quit = signal(SIGQUIT, SIG_IGN);
	if (isatty(STDIN_FILENO))
		line = readline("> ");
	else
		line = read_noninteractive_line();
	while (line)
	{
		if (ft_strncmp(line, redir->file, ft_strlen(redir->file) + 1) == 0)
			return (finish_heredoc(0, line, old_quit));
		if (handle_heredoc_line(write_fd, line, redir, shell) != 0)
			return (finish_heredoc(1, line, old_quit));
		free(line);
		if (isatty(STDIN_FILENO))
			line = readline("> ");
		else
			line = read_noninteractive_line();
	}
	print_heredoc_warning(redir->file);
	return (finish_heredoc(0, NULL, old_quit));
}

int	process_heredoc(t_redir *redir, t_shell *shell)
{
	if (!redir || redir->type != REDIR_HEREDOC)
		return (-1);
	return (create_heredoc_fd(redir, shell));
}
