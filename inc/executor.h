#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"
# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>

extern volatile sig_atomic_t	g_exit_status;

typedef struct s_hd_fd //
{
	int fd;
	struct s_hd_fd *next;
}								t_hd_fd;

// exec_ast.c
int								exec_ast(t_ast_node *node, t_shell *shell);

// execute_nods.c
int								exec_command(t_ast_node *node, t_shell *shell);
int								exec_and(t_ast_node *node, t_shell *shell);
int								exec_or(t_ast_node *node, t_shell *shell);
int								exec_subshell(t_ast_node *node, t_shell *shell);

// pipe.c
int								exec_pipe(t_ast_node *node, t_shell *shell);

// heredoc.c
int								has_heredoc(t_redir *redir);
int								process_heredoc(t_redir *redir);

// heredoc_fds.c
int								create_heredoc_fd(char *delimiter);
int								fill_heredoc_pipe(int write_fd,
									char *delimiter);
void							clear_heredoc_fds(t_hd_fd *head);
int								collect_heredoc_fds(t_redir *redir,
									t_hd_fd **head);
int								next_heredoc_fd(t_hd_fd **head);

// exec_simple_command.c
int								get_child_status(int status);
int								exec_external(t_ast_node *node, t_shell *shell);
int								exec_simple_command(t_ast_node *node,
									t_shell *shell);
char							*find_command_path(char *cmd, char **envp);

// redirection.c
int								apply_redirections(t_redir *redir);

// cd.c
int								exec_builtin_cd(char **args, t_shell *shell);
char							*get_cd_target(char **args, t_shell *shell);

// env_utils.c
char							*get_env_value_executor(char **envp, char *key);
int								update_env_value(t_shell *shell, char *key,
									char *value);

// execute.c
int								exec_builtin(t_ast_node *node, t_shell *shell);
int								exec_builtin_pwd(void);
int								exec_builtin_echo(char **args, t_shell *shell);
int								exec_builtin_export(char **args,
									t_shell *shell);
int								exec_builtin_env(char **args, t_shell *shell);

// execute_2.c
int								exec_builtin_with_redir(t_ast_node *node,
									t_shell *shell);

// exit.c
int								exec_builtin_exit(char **args, t_shell *shell);

// export_utils.c
void							sort_export(char **export);
int								print_export_line(char *entry);
int								handle_export_no_value(char *arg,
									t_shell *shell);
int								handle_export_with_value(char *arg, char *sep,
									t_shell *shell);

// export.c
int								print_export(t_shell *shell);
int								update_export_value(t_shell *shell, char *key,
									char *value);

// unset.c
int								exec_builtin_unset(char **args, t_shell *shell);
int								find_matching_key(char *env_line, char *key);

// utils.c
int								is_builtin(char *cmd);
int								is_n_flag(char *arg);
int								is_valid_identifier(char *str);

// error_exit.c
void							print_cmd_error(char *cmd, char *msg);
void							exit_exec_error(char *cmd, char *path,
									t_shell *shell);

// free.c
void							free_array(char **arr);
void							cleanup_shell(t_shell *shell);

// main_helpers.c
void							interactive_signals(void);
void							execution_signals(void);
char							**copy_envp(char **envp);
int								init_shell(t_shell *shell, char **envp);

#endif
