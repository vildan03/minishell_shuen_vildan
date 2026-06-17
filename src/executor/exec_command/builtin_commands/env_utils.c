
#include "executor.h"
#include "minishell.h"

static char	*build_env_entry(char *key, char *value)
{
	char	*tmp;
	char	*entry;

	tmp = ft_strjoin(key, "=");
	if (!tmp)
		return (NULL);
	entry = ft_strjoin(tmp, value);
	free(tmp);
	return (entry);
}

static int	replace_env_value(t_shell *shell, char *key, char *new_value)
{
	int		i;
	int		key_len;
	char	*entry;

	i = 0;
	key_len = ft_strlen(key);
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], key, key_len) == 0
			&& shell->env[i][key_len] == '=')
		{
			entry = build_env_entry(key, new_value);
			if (!entry)
				return (1);
			free(shell->env[i]);
			shell->env[i] = entry;
			return (0);
		}
		i++;
	}
	return (1);
}

static int	add_env_value(t_shell *shell, char *key, char *new_value)
{
	char	**new_envp;
	char	*entry;
	int		len;

	len = 0;
	while (shell->env[len])
		len++;
	entry = build_env_entry(key, new_value);
	if (!entry)
		return (1);
	new_envp = malloc(sizeof(char *) * (len + 2));
	if (!new_envp)
		return (free(entry), 1);
	len = -1;
	while (shell->env[++len])
		new_envp[len] = shell->env[len];
	new_envp[len++] = entry;
	new_envp[len] = NULL;
	free(shell->env);
	shell->env = new_envp;
	return (0);
}

int	update_env_value(t_shell *shell, char *key, char *new_value)
{
	if (!shell || !shell->env || !key || !new_value)
		return (1);
	if (replace_env_value(shell, key, new_value) == 0)
		return (0);
	return (add_env_value(shell, key, new_value));
}
char	*get_env_value_executor(char **envp, char *key)
{
	int i;
	int key_len;

	if (!envp || !key)
		return (NULL);
	key_len = ft_strlen(key);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], key, key_len) == 0 && envp[i][key_len] == '=')
			return (envp[i] + key_len + 1);
		i++;
	}
	return (NULL);
}