#include "executor.h"
#include "minishell.h"

char	*get_old_pwd(t_shell *shell)
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

char	*get_new_pwd(char *target)
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
