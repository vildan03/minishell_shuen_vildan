#ifndef EXPANDER_H
# define EXPANDER_H

# include "parser.h"

typedef struct s_env t_env;

// expander.c
char    *expand_string(char *raw, t_env *env, int status);
char    *process_var(char *res, char *raw, int *i, t_env *env, int status);
char    *extract_and_replace_var(char *str, int *i, t_env *env, int status);
void    expand_command_args(t_ast_node *node, t_env *env, int status);

// expander_utils.c
int     is_env_char(char c);
char    *get_env_value(char *key, t_env *env);
char    *append_char(char *str, char c);
char    *append_string(char *str, char *append);

// expander_utils_2.c
void toggle_quotes(char c, int *sq, int *dq);
void expand_redirections(t_redir *redir_list, t_env *env, int status);
int	count_valid_args(char **args);

#endif
