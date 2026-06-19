#include "executor.h"
#include "expander.h"
#include "minishell.h"

int	exec_command(t_ast_node *node, t_shell *shell)
{
	if (!node)
		return (1);
	if ((!node->args || !node->args[0]) && node->redir)
		return (exec_redir_only(node, shell));
	if (!node->args || !node->args[0])
		return (0);
	if (is_builtin(node->args[0]))
		return (exec_builtin_with_redir(node, shell));
	return (exec_simple_command(node, shell));
}

int	exec_and(t_ast_node *node, t_shell *shell)
{
	int	left_status;

	if (!node || !node->left || !node->right)
		return (1);
	left_status = exec_ast(node->left, shell);
	shell->last_exit_status = left_status;
	if (left_status == 0)
		return (exec_ast(node->right, shell));
	return (left_status);
}

int	exec_or(t_ast_node *node, t_shell *shell)
{
	int	left_status;

	if (!node || !node->left || !node->right)
		return (1);
	left_status = exec_ast(node->left, shell);
	shell->last_exit_status = left_status;
	if (left_status != 0)
		return (exec_ast(node->right, shell));
	return (left_status);
}
int	exec_subshell(t_ast_node *node, t_shell *shell)
{
	pid_t	pid;
	int		status;
	int		exit_code;

	if (!node || !node->left)
		return (0);
	pid = fork();
	if (pid == -1)
		return (perror("minishell: subshell fork"), 1);
	if (pid == 0)
	{
			if (node->redir && apply_redirections(node->redir, shell) != 0)
			{
				cleanup_shell(shell);
			exit(1);
		}
		exit_code = exec_ast(node->left, shell);
		cleanup_shell(shell);
		exit(exit_code);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
