# include "expander.h"

static bool	match_pattern_recursive(char *pattern, char *filename)
{
	if (*pattern == '\0')
		return (*filename == '\0');
	if (*pattern == '*')
	{
		if (match_pattern_recursive(pattern + 1, filename))
			return (true);
		return (*filename != '\0'
			&& match_pattern_recursive(pattern, filename + 1));
	}
	if (*filename != '\0' && *pattern == *filename)
		return (match_pattern_recursive(pattern + 1, filename + 1));
	return (false);
}

bool	match_pattern(char *pattern, char *filename)
{
	if (!pattern || !filename)
		return (false);
	if ((filename[0] == '.' && filename[1] == '\0')
		|| (filename[0] == '.' && filename[1] == '.'
			&& filename[2] == '\0'))
		return (false);
	if (filename[0] == '.' && pattern[0] != '.')
		return (false);
	return (match_pattern_recursive(pattern, filename));
}

bool	has_unquoted_star(char *str)
{
	int	i;
	int	sq;
	int	dq;

	i = 0;
	sq = 0;
	dq = 0;
	if (!str)
		return (false);
	while (str[i])
	{
		if (str[i] == '\'' && !dq)
			sq = !sq;
		else if (str[i] == '"' && !sq)
			dq = !dq;
		else if (str[i] == '*' && !sq && !dq)
			return (true);
		i++;
	}
	return (false);
}

char	**add_match_to_array(char **matches, char *new_match)
{
	int		i;
	char	**new_array;

	i = 0;
	while (matches && matches[i])
		i++;
	new_array = malloc(sizeof(char *) * (i + 2));
	if (!new_array)
		return (NULL);
	i = 0;
	while (matches && matches[i])
	{
		new_array[i] = matches[i];
		i++;
	}
	new_array[i] = ft_strdup(new_match);
	new_array[i + 1] = NULL;
	free(matches);
	return (new_array);
}

char	**get_wildcard_matches(char *pattern)
{
	DIR				*dir;
	struct dirent	*entry;
	char			**matches;

	matches = NULL;
	dir = opendir(".");
	if (!dir)
		return (NULL);
	entry = readdir(dir);
	while (entry != NULL)
	{
		if (match_pattern(pattern, entry->d_name))
		{
			matches = add_match_to_array(matches, entry->d_name);
		}
		entry = readdir(dir);
	}
	closedir(dir);
	return (matches);
}