
#include "../../../../inc/executor.h"
#include "../../../../inc/minishell.h"

static int	print_env_error(char *arg)
{
	ft_putstr_fd("minishell: env: '", 2);
	ft_putstr_fd(arg, 2);
	ft_putendl_fd("': No such file or directory", 2);
	return (1);
}

int	exec_builtin(t_ast_node *node, t_shell *shell)
{
	if (!node || !node->args || !node->args[0])
		return (1);
	if (ft_strncmp(node->args[0], "pwd", 4) == 0)
		return (exec_builtin_pwd(node->args, shell));
	if (ft_strncmp(node->args[0], "cd", 3) == 0)
		return (exec_builtin_cd(node->args, shell));
	if (ft_strncmp(node->args[0], "echo", 5) == 0)
		return (exec_builtin_echo(node->args, shell));
	if (ft_strncmp(node->args[0], "export", 7) == 0)
		return (exec_builtin_export(node->args, shell));
	if (ft_strncmp(node->args[0], "unset", 6) == 0)
		return (exec_builtin_unset(node->args, shell));
	if (ft_strncmp(node->args[0], "env", 4) == 0)
		return (exec_builtin_env(node->args, shell));
	if (ft_strncmp(node->args[0], "exit", 5) == 0)
		return (exec_builtin_exit(node->args, shell));
	return (1);
}

int	exec_builtin_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (1);
	ft_putendl_fd(cwd, 1);
	free(cwd);
	return (0);
}

int	exec_builtin_echo(char **args, t_shell *shell)
{
	int	i;
	int	newline;

	(void)shell;
	i = 1;
	newline = 1;
	while (args[i] && is_n_flag(args[i]))
	{
		newline = 0;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (newline)
		ft_putchar_fd('\n', 1);
	return (0);
}
int	exec_builtin_env(char **args, t_shell *shell)
{
	int	i;

	if (!shell || !shell->env)
		return (1);
	if (args[1])
		return (print_env_error(args[1]));
	i = 0;
	while (shell->env[i])
	{
		ft_putendl_fd(shell->env[i], 1);
		i++;
	}
	return (0);
}

int	exec_builtin_export(char **args, t_shell *shell)
{
	char	*sep;
	int		i;
	int		status;

	if (!args[1])
		return (print_export(shell));
	i = 1;
	status = 0;
	while (args[i])
	{
		sep = ft_strchr(args[i], '=');
		if (!sep)
		{
			if (handle_export_no_value(args[i], shell) == 1)
				status = 1;
		}
		else
		{
			if (handle_export_with_value(args[i], sep, shell) == 1)
				status = 1;
		}
		i++;
	}
	return (status);
}
