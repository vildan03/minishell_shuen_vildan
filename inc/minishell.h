#ifndef MINISHELL_H
# define MINISHELL_H

# include "../inc/parser.h"

typedef struct s_token		t_token;
typedef struct s_ast_node	t_ast_node;

typedef struct s_shell
{
	char					**env;
	char					**export;
	char					*current_input;
	int						last_exit_status;
	t_token					*token_list;
	t_ast_node				*ast_root;
}							t_shell;

typedef struct s_env
{
	char					*key;
	char					*value;
	struct s_env			*next;
}							t_env;

void						append_env_node(t_env **head, t_env *new_node);
void						extract_key_value(char *env_str, char **key,
								char **value);
void						free_env_list(t_env *env);
t_env						*init_env(char **envp);

#endif
