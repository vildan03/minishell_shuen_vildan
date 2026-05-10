#include "../../inc/minishell.h"
#include "../../inc/executor.h"

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strncmp(cmd, "pwd", 4) == 0)
		return (1);
	if (ft_strncmp(cmd, "cd", 3) == 0)
		return (1);
	if (ft_strncmp(cmd, "echo", 5) == 0)
		return (1);
	if (ft_strncmp(cmd, "export", 7) == 0)
		return (1);
	if (ft_strncmp(cmd, "unset", 6) == 0)
		return (1);
	if (ft_strncmp(cmd, "env", 4) == 0)
		return (1);
	if (ft_strncmp(cmd, "exit", 5) == 0)
		return (1);
	return (0);
}
int	exec_builtin(t_ast_node *node, t_shell *shell)
{
	if (!node || !node->args || !node->args[0])
		return (1);
	if (ft_strncmp(node->args[0], "pwd", 4) == 0)
		return (exec_builtin_pwd(node->args, shell));
	if (ft_strncmp(node->args[0], "cd", 3) == 0)
		return (exec_builtin_cd(node->args,shell));
	if (ft_strncmp(node->args[0], "echo", 5) == 0)
		return (exec_builtin_echo(node->args,shell));
	if (ft_strncmp(node->args[0], "export", 7) == 0)
		return (exec_builtin_export(node->args,shell));
	if (ft_strncmp(node->args[0], "unset", 6) == 0)
		return (exec_builtin_unset(node->args,shell));
	if (ft_strncmp(node->args[0], "env", 4) == 0)
		return (exec_builtin_env(node->args,shell));
	if (ft_strncmp(node->args[0], "exit", 5) == 0)
		return (exec_builtin_exit(node->args,shell));
	return (1);
}

int	exec_external(t_ast_node *node, t_shell *shell)
{
	(void)node;
	(void)shell;
	return (0);
}
