#include "../../inc/executor.h"
#include "../../inc/minishell.h"

int	main(void)
{
	t_shell		shell;
	t_ast_node	node;
	char		*args[2];
	int			status;

	args[0] = "pwd";
	args[1] = NULL;
	shell.env = NULL;
	shell.last_exit_status = 0;
	node.type = NODE_COMMAND;
	node.args = args;
	node.redir = NULL;
	node.left = NULL;
	node.right = NULL;
	status = exec_command(&node, &shell);
	if (status != 0)
		return (printf("FAIL: exec_command returned %d\n", status), 1);
	printf("PASS: exec_command builtin dispatch\n");
	return (0);
}
