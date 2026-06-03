#include "../../inc/minishell.h"
#include "../../inc/executor.h"

int	exec_command(t_ast_node *node, t_shell *shell)
{
	if (!node)
		return (1); // think about it well
	if(!node->args || !node->args[0])
		return(0);
	if (is_builtin(node->args[0]))
		return (exec_builtin(node, shell));
	return (exec_external(node, shell));
}

int	exec_and(t_ast_node *node, t_shell *shell)
{
	int status;
	
	status = exec_ast(node->left, shell);
	if(status == 0)
		status = exec_ast(node->right, shell);
	return (status);
}

int	exec_or(t_ast_node *node, t_shell *shell)
{
	int status;

	status = exec_ast(node->left, shell);
	if(status != 0)
		status = exec_ast(node->right, shell);
	return (status);
}

int	exec_pipe(t_ast_node *node, t_shell *shell)
{
	(void)node;
	(void)shell;
	return (0);
}

int	exec_subshell(t_ast_node *node, t_shell *shell)
{
	(void)node;
	(void)shell;
	return (0);
}
