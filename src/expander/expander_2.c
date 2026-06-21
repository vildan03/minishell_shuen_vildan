#include "expander.h"

static char	*extract_and_replace_var(char *str, int *i, char **env,
		int last_status)
{
	int		start;
	char	*key;
	char	*val_dup;

	(*i)++;
	if (str[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(last_status));
	}
	if (ft_isdigit(str[*i]))
		return ((*i)++, ft_strdup(""));
	start = *i;
	while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
		(*i)++;
	key = ft_substr(str, start, *i - start);
	val_dup = ft_strdup(get_env_value(env, key));
	free(key);
	return (val_dup);
}

static char	*process_var(char *res, char *raw, int *i, char **env, int status)
{
	char	*tmp;

	tmp = extract_and_replace_var(raw, i, env, status);
	res = append_string(res, tmp);
	free(tmp);
	return (res);
}

char	*expand_string_2(char *raw, char **env, int status, char *res, int *i,
		int sq, int dq, int *skip_inc)
{
	*skip_inc = 0;
	if (raw[*i] == '$' && !sq && is_env_char(raw[*i + 1]))
	{
		*skip_inc = 1;
		return (process_var(res, raw, i, env, status));
	}
	if (raw[*i] == '*' && (sq || dq))
		return (append_char(res, 1));
	return (append_char(res, raw[*i]));
}

void	filter_empty_args(t_ast_node *node, char **new_args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (node->args[i] != NULL)
	{
		if (node->args[i][0] != '\0')
			new_args[j++] = node->args[i];
		else
			free(node->args[i]);
		i++;
	}
	new_args[j] = NULL;
	free(node->args);
	node->args = new_args;
}

void	unmask_args(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args && args[i])
	{
		if (args[i][0] == 3 && args[i][1] == '\0')
			args[i][0] = '\0';
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == 1)
				args[i][j] = '*';
			j++;
		}
		i++;
	}
}
