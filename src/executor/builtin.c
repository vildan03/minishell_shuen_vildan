#include "../../inc/minishell.h"
#include "../../inc/executor.h"

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (1);
	if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	if (ft_strcmp(cmd, "export") == 0)
		return (1);
	if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	if (ft_strcmp(cmd, "env") == 0)
		return (1);
	if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	return (0);
}
int	exec_builtin(t_ast_node *node, t_shell *shell)
{
	if (!node || !node->args || !node->args[0])
		return (1);
	if (ft_strcmp(node->args[0], "pwd") == 0)
		return (exec_builtin_pwd(node->args, shell));
	if (ft_strcmp(node->args[0], "cd") == 0)
		return (exec_builtin_cd(node->args,shell));
	if (ft_strcmp(node->args[0], "echo") == 0)
		return (exec_builtin_echo(node->args,shell));
	if (ft_strcmp(node->args[0], "export") == 0)
		return (exec_builtin_export(node->args,shell));
	if (ft_strcmp(node->args[0], "unset") == 0)
		return (exec_builtin_unset(node->args,shell));
	if (ft_strcmp(node->args[0], "env") == 0)
		return (exec_builtin_env(node->args,shell));
	if (ft_strcmp(node->args[0], "exit") == 0)
		return (exec_builtin_exit(node->args,shell));
}
