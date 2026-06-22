#include "expander.h"

static char	*process_expand_char(char *raw, char **env, int status, char *res,
		int *i, int *sq, int *dq, int *skip_inc)
{
	if ((raw[*i] == '\'' && !*dq) || (raw[*i] == '"' && !*sq))
		toggle_quotes(raw[*i], sq, dq);
	else if (raw[*i] == '$' && (raw[*i + 1] == '"' || raw[*i + 1] == '\'') 
			&& !*sq && !*dq && (*i == 0 || raw[*i - 1] != '$'))
		(*i)++;
	else
		res = expand_string_2(raw, env, status, res, i, *sq, *dq, skip_inc);
	return (res);
}

char	*expand_string(char *raw, char **env, int status)
{
	int		sq;
	int		dq;
	int		i;
	int		skip_inc;
	char	*res;

	sq = 0;
	dq = 0;
	i = 0;
	res = ft_strdup("");
	while (raw[i])
	{
		skip_inc = 0;
		res = process_expand_char(raw, env, status, res, &i, &sq, &dq, &skip_inc);
		if (!skip_inc)
			i++;
	}
	return (res);
}

static void	expand_command_args_2(t_ast_node *node, char **env, int last_status,
		char **new_args)
{
	expand_wildcards(node);
	expand_redirections(node->redir, env, last_status);
	new_args = malloc(sizeof(char *) * (count_valid_args(node->args) + 1));
	if (!new_args)
		return ;
	filter_empty_args(node, new_args);
	unmask_args(new_args);
}

void	expand_command_args(t_ast_node *node, char **env, int last_status)
{
	int		i;
	char	*raw;
	char	*expanded;

	if (!node || !node->args)
		return ;
	i = -1;
	while (node->args[++i] != NULL)
	{
		raw = node->args[i];
		expanded = expand_string(raw, env, last_status);
		if ((ft_strchr(raw, '\'') || ft_strchr(raw, '"')) && expanded
					&& expanded[0] == '\0')
		{
			free(expanded);
			expanded = ft_strdup("\2");
		}
		free(raw);
		node->args[i] = expanded;
	}
	expand_command_args_2(node, env, last_status, NULL);
}
