#include "executor.h"
#include "minishell.h"

static void	cleanup_and_exit(t_shell *shell, int status)
{
	cleanup_process_state(shell, shell->ast_root, shell->token_list);
	exit(status);
}

static int	apply_child_redirections(t_ast_node *node, t_shell *shell)
{
	free(shell->current_input);
	shell->current_input = NULL;
	if (apply_redirections(node->redir, shell) == -1)
		return (1);
	return (0);
}

static void	exec_external_child(t_ast_node *node, t_shell *shell)
{
	char	*path;
	int		status;

	path = find_command_path(node->args[0], shell->env);
	status = validate_exec_path(node->args[0], path);
	if (status != 0)
	{
		free(path);
		cleanup_and_exit(shell, status);
	}
	execve(path, node->args, shell->env);
	perror(node->args[0]);
	free(path);
	cleanup_and_exit(shell, 126);
}

void	exec_command_child(t_ast_node *node, t_shell *shell)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (!node || apply_child_redirections(node, shell) != 0)
		cleanup_and_exit(shell, 1);
	if (!node->args || !node->args[0])
		cleanup_and_exit(shell, 0);
	if (is_builtin(node->args[0]))
		cleanup_and_exit(shell, exec_builtin(node, shell));
	exec_external_child(node, shell);
}
