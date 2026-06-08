#ifndef EXPANDER_H
# define EXPANDER_H

# include "parser.h"

typedef struct s_env	t_env;

// expander.c
char					*expand_string(char *raw, char **env, int status);
char					*process_var(char *res, char *raw, int *i, char **env,
							int status);
char					*extract_and_replace_var(char *str, int *i, char **env,
							int status);
void					expand_command_args(t_ast_node *node, char **env,
							int status);

// expander_utils.c
int						is_env_char(char c);
char					*get_env_value(char **env, char *key);
char					*append_char(char *str, char c);
char					*append_string(char *str, char *append);

// expander_utils_2.c
void					toggle_quotes(char c, int *sq, int *dq);
void					expand_redirections(t_redir *redir_list, char **env,
							int status);
int						count_valid_args(char **args);

#endif
