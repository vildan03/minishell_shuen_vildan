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
int	exec_ast(t_ast_node *node, t_shell *shell)
{
	if (!node)
		return (0);
	if (node->type == NODE_COMMAND)
		return(exec_command(node, shell));
	if (node->type == NODE_AND)
		return(exec_and(node, shell));
	if (node->type == NODE_OR)
		return(exec_or(node, shell));
	if (node->type == NODE_PIPE)
		return(exec_pipe(node, shell));
	if (node->type == NODE_SUBSHELL)
		return(exec_subshell(node, shell));
	return (1);
} 
