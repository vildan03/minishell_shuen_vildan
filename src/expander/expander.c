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
	char	*res;

	sq = 0;
	dq = 0;
	i = 0;
	res = ft_strdup("");
	while (raw[i])
	{
		if ((raw[i] == '\'' && !dq) || (raw[i] == '"' && !sq))
			toggle_quotes(raw[i], &sq, &dq);
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

void	expand_command_args(t_ast_node *node, char **env, int last_status)
{
	int		i;
	char	*expanded;
	char	**new_args;

	if (!node || !node->args)
		return ;
	i = -1;
	while (node->args[++i] != NULL)
	{
		expanded = expand_string(node->args[i], env, last_status);
		free(node->args[i]);
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
