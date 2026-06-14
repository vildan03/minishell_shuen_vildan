# include "expander.h"

//Used to check and to replace algorithm side

bool	match_pattern_recursive(char *pattern, char *str)
{
	if (*pattern == '\0' && *str == '\0')
		return (true);
	if (*pattern == '*')
	{
		if (match_pattern_recursive(pattern + 1, str))
			return (true);
		if (*str != '\0' && match_pattern_recursive(pattern, str + 1))
			return (true);
	}
	if (*pattern == *str && *str != '\0')
		return (match_pattern_recursive(pattern + 1, str + 1));
	return (false);
}

bool	match_pattern(char *pattern, char *str)
{
	if (str[0] == '.' && pattern[0] != '.')
		return (false);
	return (match_pattern_recursive(pattern, str));
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
