#include "../../../inc/minishell.h"
#include "../../../inc/executor.h"

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