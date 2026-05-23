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
int	exec_builtin_pwd();
int	exec_builtin_cd(char **args, t_shell *shell);
int	exec_builtin_echo(char **args, t_shell *shell);
int	exec_builtin_export(char **args, t_shell *shell);
int	exec_builtin_unset(char **args, t_shell *shell);
int	exec_builtin_env(char **args, t_shell *shell);
int	exec_builtin_exit(char **args, t_shell *shell);
int	is_n_flag(char *arg);
char	*get_env_value(char **envp, char *key);
char	*get_cd_target(char **args, t_shell *shell);
int	update_env_value(t_shell *shell, char *key, char *value);
int	is_valid_identifier(char *str);
int	find_matching_key(char *env_line, char *key);

#endif
