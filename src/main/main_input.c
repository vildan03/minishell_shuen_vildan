#include "../../inc/executor.h"
#include <errno.h>

static char	*append_input_char(char *line, size_t len, char c)
{
	char	*new_line;

	new_line = malloc(len + 2);
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	if (line)
		ft_memcpy(new_line, line, len);
	new_line[len] = c;
	new_line[len + 1] = '\0';
	free(line);
	return (new_line);
}

static int	read_input_char(char *c)
{
	ssize_t	bytes;

	bytes = read(STDIN_FILENO, c, 1);
	if (bytes == -1 && errno == EINTR)
		return (read_input_char(c));
	return ((int)bytes);
}

char	*read_noninteractive_line(void)
{
	char	*line;
	char	c;
	size_t	len;
	int		bytes;

	line = NULL;
	len = 0;
	bytes = read_input_char(&c);
	while (bytes > 0)
	{
		if (c == '\n')
			return (line);
		line = append_input_char(line, len++, c);
		if (!line)
			return (NULL);
		bytes = read_input_char(&c);
	}
	if (!line && bytes <= 0)
		return (NULL);
	return (line);
}
char	**copy_envp(char **envp)
{
	char	**copy;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		copy[i] = ft_strdup(envp[i]);
		if (!copy[i])
			return (free_partial_copy(copy, i));
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
