#include "../../../inc/minishell.h"
#include "../../../inc/executor.h"

static void	print_export_line(char *entry)
{
	char	*eq;
	int		key_len;

	eq = ft_strchr(entry, '=');
	ft_putstr_fd("declare -x ", 1);
	if (!eq)
	{
		ft_putendl_fd(entry, 1);
		return ;
	}
	key_len = eq - entry;
	write(1, entry, key_len);
	ft_putstr_fd("=\"", 1);
	ft_putstr_fd(eq + 1, 1);
	ft_putendl_fd("\"", 1);
}

int	print_export(t_shell *shell)
{
	int	i;

	if (!shell || !shell->export)
		return (1);
	i = 0;
	while (shell->export[i])
	{
		print_export_line(shell->export[i]);
		i++;
	}
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
	if (status == 0
		&& update_env_value(shell, key, sep + 1) == 1)
		status = 1;
	free(key);
	return (status);
}
