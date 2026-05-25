#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
#include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

typedef enum e_node_type
{
	NODE_COMMAND,
	NODE_PIPE,
	NODE_AND,
	NODE_OR,
	NODE_SUBSHELL
}						t_node_type;

typedef enum e_redir_type
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_HEREDOC,
	REDIR_APPEND
}						t_redir_type;

typedef struct s_redir
{
	t_redir_type		type;
	char				*file;
	struct s_redir		*next;
}						t_redir;

typedef struct s_ast_node
{
	t_node_type			type;

	char				**args;
	t_redir				*redir;

	struct s_ast_node	*left;
	struct s_ast_node	*right;
}						t_ast_node;

typedef struct s_shell
{
	char **envp;
	int	last_exit_status;
} t_shell;

typedef struct s_env {
    char            *key;
    char            *value;
    struct s_env    *next;
} t_env;

# include "parser.h"
# include "expander.h"

void append_env_node(t_env **head, t_env *new_node);
void extract_key_value(char *env_str, char **key, char **value);
void free_env_list(t_env *env);
t_env *init_env(char **envp);

#endif
