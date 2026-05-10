#ifndef EXECUTOR_H
# define EXECUTOR_H

#include "minishell.h"

int	exec_ast(t_ast_node *node, t_shell *shell);
int	exec_command(t_ast_node *node, t_shell *shell);
int	exec_and(t_ast_node *node, t_shell *shell);
int	exec_or(t_ast_node *node, t_shell *shell);
int	exec_pipe(t_ast_node *node, t_shell *shell);
int	exec_subshell(t_ast_node *node, t_shell *shell);
int	is_builtin(char *cmd);

#endif