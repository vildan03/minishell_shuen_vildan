#ifndef EXECUTOR_H
# define EXECUTOR_H

#include "minishell.h"

int	exec_ast(t_ast_node *node, t_shell *shell);
int	exec_command(t_ast_node *node, t_shell *shell);
int	exec_and(t_ast_node *node, t_shell *shell);
int	exec_or(t_ast_node *node, t_shell *shell);
int	exec_pipe(t_ast_node *node, t_shell *shell);
int	exec_subshell(t_ast_node *node, t_shell *shell);
int	exec_builtin(t_ast_node *node, t_shell *shell);
int	exec_external(t_ast_node *node, t_shell *shell);
int	is_builtin(char *cmd);
int	exec_builtin_pwd(void);
int	exec_builtin_cd(char **args, t_shell *shell);
int	exec_builtin_echo(char **args, t_shell *shell);
int	exec_builtin_export(char **args, t_shell *shell);
int	exec_builtin_unset(char **args, t_shell *shell);
int	exec_builtin_env(char **args, t_shell *shell);
int	exec_builtin_exit(char **args, t_shell *shell);

#endif
