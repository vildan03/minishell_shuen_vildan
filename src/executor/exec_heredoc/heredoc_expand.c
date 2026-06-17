#include "../../../inc/executor.h"
#include "../../../inc/expander.h"

static char	*expand_heredoc_var(char *line, int *i, char **env, int status)
{
	int		start;
	char	*key;
	char	*value;

	(*i)++;
	if (line[*i] == '?')
		return ((*i)++, ft_itoa(status));
	start = *i;
	while (line[*i] && (ft_isalnum(line[*i]) || line[*i] == '_'))
		(*i)++;
	key = ft_substr(line, start, *i - start);
	value = ft_strdup(get_env_value(env, key));
	free(key);
	return (value);
}

char	*expand_heredoc_line(char *line, char **env, int status)
{
	int		i;
	char	*value;
	char	*expanded;

	i = 0;
	expanded = ft_strdup("");
	if (!expanded)
		return (NULL);
	while (line[i])
	{
		if (line[i] == '$' && is_env_char(line[i + 1]))
		{
			value = expand_heredoc_var(line, &i, env, status);
			if (!value)
				return (free(expanded), NULL);
			expanded = append_string(expanded, value);
			free(value);
			if (!expanded)
				return (NULL);
			continue ;
		}
		expanded = append_char(expanded, line[i++]);
		if (!expanded)
			return (NULL);
	}
	return (expanded);
}
