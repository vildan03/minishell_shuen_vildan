#include "expander.h"

static int	should_skip_dollar_quote(char *raw, int i, int sq)
{
	return (raw[i] == '$' && !sq && (raw[i + 1] == '"'
			|| raw[i + 1] == '\''));
}

static char	*finalize_expanded_string(char *res, int has_quotes)
{
	if (!res)
		return (NULL);
	if (res[0] != '\0' || !has_quotes)
		return (res);
	free(res);
	return (ft_strdup("\3"));
}

char	*expand_string(char *raw, char **env, int status)
{
	int		sq;
	int		dq;
	int		i;
	int		has_quotes;
	int		skip_inc;
	char	*res;

	sq = 0;
	dq = 0;
	i = 0;
	has_quotes = 0;
	res = ft_strdup("");
	if (!res)
		return (NULL);
	while (raw[i])
	{
		skip_inc = 0;
		if ((raw[i] == '\'' && !dq) || (raw[i] == '"' && !sq))
		{
			has_quotes = 1;
			toggle_quotes(raw[i], &sq, &dq);
		}
		else if (should_skip_dollar_quote(raw, i, sq))
		{
			i++;
			continue ;
		}
		else
		{
			res = expand_string_2(raw, env, status, res, &i, sq, dq, &skip_inc);
			if (!res)
				return (NULL);
		}
		if (!skip_inc)
			i++;
	}
	return (finalize_expanded_string(res, has_quotes));
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
		if (!expanded)
			return ;
		free(raw);
		node->args[i] = expanded;
	}
	expand_command_args_2(node, env, last_status, NULL);
}
