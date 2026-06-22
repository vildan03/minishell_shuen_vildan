#include "executor.h"
#include "minishell.h"
#include <errno.h>
#include <string.h>

static int	print_cd_error(char *target, char *msg)
{
	ft_putstr_fd("minishell: cd", 2);
	if (target)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(target, 2);
	}
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
	return (1);
}

static int	print_cd_errno(char *target)
{
	return (print_cd_error(target, strerror(errno)));
}

static char	*get_cd_target(char **args, t_shell *shell)
{
	char	*target;

	if (!shell || !shell->env)
		return (NULL);
	if (args[1] && args[2])
		return (print_cd_error(NULL, "too many arguments"), NULL);
	if (!args[1])
	{
		target = get_env_value_executor(shell->env, "HOME");
		if (!target)
			print_cd_error(NULL, "HOME not set");
		else if (*target == '\0')
			return (".");
		return (target);
	}
	if (ft_strncmp(args[1], "-", 2) == 0)
	{
		target = get_env_value_executor(shell->env, "OLDPWD");
		if (!target)
			print_cd_error(NULL, "OLDPWD not set");
		return (target);
	}
	return (args[1]);
}

static int	update_cd_state(t_shell *shell, char **args, char *old_pwd,
		char *new_pwd)
{
	if (old_pwd && update_env_value(shell, "OLDPWD", old_pwd) != 0)
		return (1);
	if (new_pwd && update_env_value(shell, "PWD", new_pwd) != 0)
		return (1);
	if (args[1] && ft_strncmp(args[1], "-", 2) == 0 && new_pwd)
	{
		if (write_builtin_str(new_pwd, "cd") != 0 || write_builtin_char('\n',
				"cd") != 0)
			return (1);
	}
	return (0);
}

static char	*get_old_pwd(t_shell *shell)
{
	char	*old_pwd;
	char	*pwd_value;

	old_pwd = getcwd(NULL, 0);
	if (!old_pwd && shell && shell->env)
	{
		pwd_value = get_env_value_executor(shell->env, "PWD");
		if (pwd_value)
			old_pwd = ft_strdup(pwd_value);
	}
	return (old_pwd);
}

static char	*get_new_pwd(char *target)
{
	char	*new_pwd;

	new_pwd = getcwd(NULL, 0);
	if (new_pwd && ft_strcmp(target, "//") == 0 && ft_strcmp(new_pwd, "/") == 0)
	{
		free(new_pwd);
		new_pwd = ft_strdup("//");
	}
	return (new_pwd);
}

int	exec_builtin_cd(char **args, t_shell *shell)
{
	char	*target;
	char	*old_pwd;
	char	*new_pwd;

	target = get_cd_target(args, shell);
	if (!target)
		return (1);
	old_pwd = get_old_pwd(shell);
	if (chdir(target) != 0)
		return (free(old_pwd), print_cd_errno(target));
	if (!old_pwd && errno == ENOENT)
		ft_putendl_fd("cd: error retrieving current directory: getcwd: "
						"cannot access parent directories: No such file or directory",
						2);
	new_pwd = get_new_pwd(target);
	if (update_cd_state(shell, args, old_pwd, new_pwd) != 0)
		return (free(old_pwd), free(new_pwd), 1);
	return (free(old_pwd), free(new_pwd), 0);
}
