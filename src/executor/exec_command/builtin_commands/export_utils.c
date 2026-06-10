
#include "../../../../inc/executor.h"
#include "../../../../inc/minishell.h"

static int	write_export_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (write(STDOUT_FILENO, &str[i], 1) == -1)
			return (perror("minishell: export: write error"), 1);
		i++;
	}
	return (0);
}

void	sort_export(char **export)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (export[i])
	{
		j = i + 1;
		while (export[j])
		{
			if (ft_strcmp(export[i], export[j]) > 0)
			{
				tmp = export[i];
				export[i] = export[j];
				export[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	print_export_line(char *entry)
{
	char	*eq;
	int		key_len;

	eq = ft_strchr(entry, '=');
	if (write_export_str("declare -x ") != 0)
		return (1);
	if (!eq)
	{
		if (write_export_str(entry) != 0 || write_export_str("\n") != 0)
			return (1);
		return (0);
	}
	key_len = eq - entry;
	if (write(1, entry, key_len) < 0)
		return (perror("minishell: export: write error"), 1);
	if (write_export_str("=\"") != 0 || write_export_str(eq + 1) != 0
		|| write_export_str("\"\n") != 0)
		return (1);
	return (0);
}

static void	print_export_error(char *arg)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(arg, 2);
	ft_putendl_fd("': not a valid identifier", 2);
}

int	handle_export_no_value(char *arg, t_shell *shell)
{
	if (!is_valid_identifier(arg))
	{
		print_export_error(arg);
		return (1);
	}
	return (update_export_value(shell, arg, NULL));
}

int	handle_export_with_value(char *arg, char *sep, t_shell *shell)
{
	char	*key;
	int		key_len;
	int		status;

	key_len = sep - arg;
	key = ft_substr(arg, 0, key_len);
	if (!key)
		return (1);
	if (!is_valid_identifier(key))
	{
		print_export_error(arg);
		free(key);
		return (1);
	}
	status = 0;
	if (update_export_value(shell, key, sep + 1) == 1)
		status = 1;
	if (status == 0 && update_env_value(shell, key, sep + 1) == 1)
		status = 1;
	free(key);
	return (status);
}
