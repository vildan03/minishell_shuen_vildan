#ifndef EXPANDER_H
# define EXPANDER_H

#include "minishell.h"
# include <dirent.h>
# include <sys/types.h>

// expander.c
char	*expand_string(char *raw, char **env, int status);
void	expand_command_args(t_ast_node *node, char **env, int status);

// expander_utils.c
int		is_env_char(char c);
char	*get_env_value(char **env, char *key);
char	*append_char(char *str, char c);
char	*append_string(char *str, char *append);

// expander_utils_2.c
void	toggle_quotes(char c, int *sq, int *dq);
void	expand_redirections(t_redir *redir_list, char **env, int status);
int		count_valid_args(char **args);

// wildcard_utils.c
bool	match_pattern(char *pattern, char *filename);
bool	has_unquoted_star(char *str);
char	**get_wildcard_matches(char *pattern);

// wildcard_utils_2.c
char	**splice_wildcard_matches(char **args, char **matches, int target_idx);
void	expand_wildcards(t_ast_node *node);

#endif
