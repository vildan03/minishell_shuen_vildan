#include "executor.h"
#include "minishell.h"

int	exec_ast(t_ast_node *node, t_shell *shell)
{
	if (!node)
		return (0);
	if (node->type == NODE_COMMAND)
		return (exec_command(node, shell));
	if (node->type == NODE_AND)
		return (exec_and(node, shell));
	if (node->type == NODE_OR)
		return (exec_or(node, shell));
	if (node->type == NODE_PIPE)
		return (exec_pipe(node, shell));
	if (node->type == NODE_SUBSHELL)
		return (exec_subshell(node, shell));
	return (1);
}
