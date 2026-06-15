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

#endif
