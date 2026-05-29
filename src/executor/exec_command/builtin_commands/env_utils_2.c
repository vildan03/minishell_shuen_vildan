
#include "../../../../inc/minishell.h"
#include "../../../../inc/executor.h"
char	*get_env_value_executor(char **envp, char *key)
{
	int		i;
	int		key_len;

	if (!envp || !key)
		return (NULL);
	key_len = ft_strlen(key);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], key, key_len) == 0
			&& envp[i][key_len] == '=')
			return (envp[i] + key_len + 1);
		i++;
	}
	return (NULL);
}
