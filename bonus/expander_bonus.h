/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:49:14 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 19:56:50 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_BONUS_H
# define EXPANDER_BONUS_H

# include "minishell_bonus.h"
# include <dirent.h>
# include <sys/types.h>

typedef struct s_expand_ctx
{
	char	*raw;
	char	**env;
	int		status;
	char	*res;
	int		i;
	int		sq;
	int		dq;
	int		skip_inc;
}			t_expand_ctx;

// expander.c
char		*expand_string(char *raw, char **env, int status);
void		expand_command_args(t_ast_node *node, char **env, int status);

// expander_2.c
char		*expand_string_2(t_expand_ctx *ctx);
void		filter_empty_args(t_ast_node *node, char **new_args);
void		unmask_args(char **args);

// expander_utils.c
int			is_env_char(char c);
char		*get_env_value(char **env, char *key);
char		*append_char(char *str, char c);
char		*append_string(char *str, char *append);

// expander_utils_2.c
void		toggle_quotes(char c, int *sq, int *dq);
void		expand_redirections(t_redir *redir_list, char **env, int status);
int			count_valid_args(char **args);
char		*process_expand_char(t_expand_ctx *ctx);

// wildcard_utils.c
bool		match_pattern(char *pattern, char *filename);
bool		has_unquoted_star(char *str);
char		**get_wildcard_matches(char *pattern);
bool		match_pattern_recursive(char *pattern, char *filename);
int			count_contents(char **args);

// wildcard_utils_2.c
char		**splice_wildcard_matches(char **args, char **matches,
				int target_idx);
void		expand_wildcards(t_ast_node *node);

#endif
