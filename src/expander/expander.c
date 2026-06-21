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
	if(ft_isdigit(str[*i]))
		return((*i)++, ft_strdup(""));
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

char	*expand_string(char *raw, char **env, int status)
{
	int		sq;
	int		dq;
	int		i;
	int		has_quotes;
	char	*res;

	sq = 0;
	dq = 0;
	i = 0;
	has_quotes = 0;
	res = ft_strdup("");
<<<<<<< HEAD
		while (raw[i])
=======
	while (raw[i])
	{
		if ((raw[i] == '\'' && !dq) || (raw[i] == '"' && !sq))
		{
			has_quotes = 1;
			toggle_quotes(raw[i], &sq, &dq);
		}
		else if(raw[i] == '$' && !sq && (raw[i + 1] == '"' || raw[i + 1] == '\''))
		{
			i++;
			continue;
		}
		else if (raw[i] == '$' && !sq && is_env_char(raw[i + 1]))
>>>>>>> 96a796bf19c4b55764eed544c83a8a4dff4f53d6
		{
			if ((raw[i] == '\'' && !dq) || (raw[i] == '"' && !sq))
				toggle_quotes(raw[i], &sq, &dq);
			else if (raw[i] == '$' && raw[i + 1] == '"' && !sq
				&& (i == 0 || raw[i - 1] != '$'))
			{
				i++;
				continue ;
			}
			else if (raw[i] == '$' && !sq && is_env_char(raw[i + 1]))
			{
				res = process_var(res, raw, &i, env, status);
				continue ;
		}
		else if (raw[i] == '*' && (sq || dq))
			res = append_char(res, 1);
		else
			res = append_char(res, raw[i]);
		i++;
	}
	if(res[0] == '\0' && has_quotes)
	{
		free(res);
		res = ft_strdup("\2");
	}
	return (res);
}

static void	filter_empty_args(t_ast_node *node, char **new_args)
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

static void	unmask_args(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args && args[i])
	{
		if (args[i][0] == 2 && args[i][1] == '\0')
			args[i][0] = '\0';
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == 1)
				args[i][j] = '*';
			else if(args[i][j] == 2)
				args[i][j] = '\0';
			j++;
		}
		i++;
	}
}

void	expand_command_args(t_ast_node *node, char **env, int last_status)
{
	int		i;
	char	*raw;
	char	*expanded;
	char	**new_args;

	if (!node || !node->args)
		return ;
	i = -1;
	while (node->args[++i] != NULL)
	{
		raw = node->args[i];
		expanded = expand_string(raw, env, last_status);
		if ((ft_strchr(raw, '\'') || ft_strchr(raw, '"'))
			&& expanded && expanded[0] == '\0')
		{
			free(expanded);
			expanded = ft_strdup("\2");
		}
		free(raw);
		node->args[i] = expanded;
	}
	expand_wildcards(node);
	expand_redirections(node->redir, env, last_status);
	new_args = malloc(sizeof(char *) * (count_valid_args(node->args) + 1));
	if (!new_args)
		return ;
	filter_empty_args(node, new_args);
	unmask_args(new_args);
}
