#include "../../inc/minishell.h"
#include "../../inc/executor.h"

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

int	exec_builtin_pwd(char **args, t_shell *shell)
{
	char	*cwd;

	(void)args;
	(void)shell;
	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (1);
	ft_putendl_fd(cwd, 1);
	free(cwd);
	return (0);
}

int	exec_builtin_echo(char **args, t_shell *shell)
{
	int		i;
	int		newline;

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

char	*get_cd_target(char **args, t_shell *shell)
{
	if (!shell || !shell->env)
		return (NULL);
	if (args[1] && args[2])
		return (NULL);
	if (!args[1])
		return (get_env_value(shell->env, "HOME"));
	if (ft_strncmp(args[1], "-", 2) == 0)
		return (get_env_value(shell->env, "OLDPWD"));
	return (args[1]);
}

static int	update_cd_state(t_shell *shell, char **args,
	char *old_pwd, char *new_pwd)
{
	if (old_pwd && update_env_value(shell, "OLDPWD", old_pwd) != 0)
		return (1);
	if (new_pwd && update_env_value(shell, "PWD", new_pwd) != 0)
		return (1);
	if (args[1] && ft_strncmp(args[1], "-", 2) == 0 && new_pwd)
		ft_putendl_fd(new_pwd, 1);
	return (0);
}

int	exec_builtin_cd(char **args, t_shell *shell)
{
	char	*target;
	char	*old_pwd;
	char	*new_pwd;

	target = get_cd_target(args, shell);
	if (!target)
		return (1);
	old_pwd = getcwd(NULL, 0);
	if (chdir(target) != 0)
		return (free(old_pwd), 1);
	new_pwd = getcwd(NULL, 0);
	if (update_cd_state(shell, args, old_pwd, new_pwd) != 0)
		return (free(old_pwd), free(new_pwd), 1);
	free(old_pwd);
	free(new_pwd);
	return (0);
}
