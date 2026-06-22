/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:52:02 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 10:52:03 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/executor.h"
#include "../../../inc/expander.h"

int	process_heredoc(t_redir *redir, t_shell *shell)
{
	if (!redir || redir->type != REDIR_HEREDOC)
		return (-1);
	return (create_heredoc_fd(redir, shell));
}
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

static char	*expand_heredoc_line_2(char *expanded, char *line, int *i,
		char **env, int status)
{
	char	*value;

	value = expand_heredoc_var(line, i, env, status);
	if (!value)
		return (free(expanded), NULL);
	expanded = append_string(expanded, value);
	free(value);
	return (expanded);
}

static char	*append_substring(char *str, char *line, int start, int len)
{
	char	*sub;
	char	*new_str;

	sub = ft_substr(line, start, len);
	if (!sub)
		return (NULL);
	new_str = append_string(str, sub);
	free(sub);
	return (new_str);
}

char	*expand_heredoc_line(char *line, char **env, int status)
{
	int		i;
	int		start;
	char	*expanded;

	i = 0;
	expanded = ft_strdup("");
	if (!expanded)
		return (NULL);
	while (line[i])
	{
		start = i;
		while (line[i] && !(line[i] == '$' && is_env_char(line[i + 1])))
			i++;
		if (i > start)
			expanded = append_substring(expanded, line, start, i - start);
		if (line[i] == '$' && is_env_char(line[i + 1]))
			expanded = expand_heredoc_line_2(expanded, line, &i, env, status);
		if (!expanded)
			return (NULL);
	}
	return (expanded);
}
