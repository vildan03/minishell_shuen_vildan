#include "../../../inc/minishell.h"
#include "../../../inc/executor.h"


int	is_valid_identifier(char *str)
{
	int i;
	if (!str || !str[0])
		return (0);
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	i = 1;
	while (str[i])
		{
			if (!ft_isalnum(str[i]) && str[i] != '_')
				return (0);
			++i;
		}
		return (1);
}

int	find_matching_key(char *env_line, char *key)
{
	int	i;

	i = 0;
	while (key[i] && env_line[i] && env_line[i] == key[i])
		i++;
	if (key[i] == '\0'
		&& (env_line[i] == '=' || env_line[i] == '\0'))
		return (1);
	return (0);
}
static void	remove_env_index(char **arr, int index)
{
	free(arr[index]);
	while (arr[index + 1])
	{
		arr[index] = arr[index + 1];
		index++;
	}
	arr[index] = NULL;
}

static void	remove_from_array(char **arr, char *key)
{
	int	i;

	if (!arr || !key)
		return ;
	i = 0;
	while (arr[i])
	{
		if (find_matching_key(arr[i], key))
		{
			remove_env_index(arr, i);
			return ;
		}
		i++;
	}
}

int	exec_builtin_unset(char **args, t_shell *shell)
{
	int	i;
	int	status;

	if (!shell)
		return (1);
	i = 1;
	status = 0;
	while (args[i])
	{
		if (!is_valid_identifier(args[i]))
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			status = 1;
			i++;
			continue ;
		}
		remove_from_array(shell->env, args[i]);
		remove_from_array(shell->export, args[i]);
		i++;
	}
	return (status);
}