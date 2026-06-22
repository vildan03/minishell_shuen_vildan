#include <errno.h>
#include "executor.h"
#include "minishell.h"

static void	handle_heredoc_sigint(int sig)
{
	(void)sig;
	g_exit_status = 130;
}

static int	write_heredoc_line(int fd, char *line)
{
	if (write(fd, line, ft_strlen(line)) == -1)
		return (perror("write"), 1);
	if (write(fd, "\n", 1) == -1)
		return (perror("write"), 1);
	return (0);
}

static int	finish_heredoc(int status, char *line, void (*old_sigint)(int),
		void (*old_sigquit)(int))
{
	if (line)
		free(line);
	signal(SIGINT, old_sigint);
	signal(SIGQUIT, old_sigquit);
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
		content = expand_heredoc_line(line, shell->env,
				shell->last_exit_status);
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

static void	write_newline(void)
{
	int	r_val;

	r_val = write(2, "\n", 1);
	(void)r_val;
}

static void	write_prompt(void)
{
	int	r_val;

	r_val = write(2, "> ", 2);
	(void)r_val;
}

static char	*grow_buffer(char *buf, size_t *capacity, size_t len)
{
	char	*new_buf;

	*capacity *= 2;
	new_buf = malloc(*capacity);
	if (!new_buf)
	{
		free(buf);
		return (NULL);
	}
	ft_memcpy(new_buf, buf, len);
	free(buf);
	return (new_buf);
}

static int	read_char(int fd, char *c)
{
	ssize_t	bytes;

	if (g_exit_status == 130)
		return (-1);
	bytes = read(fd, c, 1);
	if (bytes == -1 && errno == EINTR)
		return (read_char(fd, c));
	return ((int)bytes);
}

static char	*read_line_from_fd(int fd)
{
	char	*buf;
	size_t	cap;
	size_t	len;
	char	c;

	cap = 128;
	buf = malloc(cap);
	if (!buf)
		return (NULL);
	len = 0;
	c = '\0';
	while (read_char(fd, &c) > 0 && c != '\n')
	{
		if (len + 1 >= cap)
		{
			buf = grow_buffer(buf, &cap, len);
			if (!buf)
				return (NULL);
		}
		buf[len++] = c;
	}
	if (g_exit_status == 130 || (len == 0 && c != '\n'))
		return (free(buf), NULL);
	return (buf[len] = '\0', buf);
}

static char	*get_heredoc_line(void)
{
	if (isatty(STDIN_FILENO))
		write_prompt();
	return (read_line_from_fd(STDIN_FILENO));
}

int	fill_heredoc_pipe(int write_fd, t_redir *redir, t_shell *shell)
{
	char	*line;
	void	(*old_sigint)(int);
	void	(*old_sigquit)(int);

	old_sigint = signal(SIGINT, handle_heredoc_sigint);
	old_sigquit = signal(SIGQUIT, SIG_IGN);
	line = get_heredoc_line();
	while (line)
	{
		if (g_exit_status == 130)
			return (write_newline(), finish_heredoc(130, line, old_sigint,
					old_sigquit));
		if (ft_strncmp(line, redir->file, ft_strlen(redir->file) + 1) == 0)
			return (finish_heredoc(0, line, old_sigint, old_sigquit));
		if (handle_heredoc_line(write_fd, line, redir, shell) != 0)
			return (finish_heredoc(1, line, old_sigint, old_sigquit));
		free(line);
		line = get_heredoc_line();
	}
	if (g_exit_status == 130)
		return (write_newline(), finish_heredoc(130, NULL, old_sigint,
				old_sigquit));
	print_heredoc_warning(redir->file);
	return (finish_heredoc(0, NULL, old_sigint, old_sigquit));
}
