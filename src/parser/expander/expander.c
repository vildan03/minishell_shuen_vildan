#include "expander.h"

char *extract_and_replace_var(char *str, int *i, t_env *env, int last_status)
{
    int     start;
    char    *key;
    char    *val_dup;

    (*i)++;
    if (str[*i] == '?')
    {
        (*i)++;
        return (ft_itoa(last_status)); 
    }
    start = *i;
    while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
        (*i)++;
    key = ft_substr(str, start, *i - start);
    val_dup = ft_strdup(get_env_value(key, env));
    free(key);
    return (val_dup);
}

char *process_var(char *res, char *raw, int *i, t_env *env, int status)
{
    char *tmp;

    tmp = extract_and_replace_var(raw, i, env, status);
    res = append_string(res, tmp);
    free(tmp);
    return (res);
}

char *expand_string(char *raw, t_env *env, int status)
{
    int     sq;
    int     dq;
    int     i;
    char    *res;

    sq = 0;
    dq = 0;
    i = 0;
    res = ft_strdup("");
    while (raw[i])
    {
        if ((raw[i] == '\'' && !dq) || (raw[i] == '"' && !sq))
            toggle_quotes(raw[i++], &sq, &dq);
        else if (raw[i] == '$' && !sq && is_env_char(raw[i + 1]))
            res = process_var(res, raw, &i, env, status);
        else
            res = append_char(res, raw[i++]);
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

void	expand_command_args(t_ast_node *node, t_env *env, int last_status)
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
	expand_redirections(node->redir, env, last_status);
	new_args = malloc(sizeof(char *) * (count_valid_args(node->args) + 1));
	if (!new_args)
		return ;
	filter_empty_args(node, new_args);
}
