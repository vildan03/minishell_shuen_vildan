
#include "../../../inc/minishell.h"
#include "../../../inc/executor.h"

static char	*create_export_entry(char *key, char *value)
{
	char	*tmp;
	char	*entry;

	if (!value)
		return (ft_strdup(key));
	tmp = ft_strjoin(key, "=");
	if (!tmp)
		return (NULL);
	entry = ft_strjoin(tmp, value);
	free(tmp);
	return (entry);
}

static int	replace_export_value(t_shell *shell,
	char *key, char *value)
{
	int		i;
	int		key_len;
	char	*entry;

	i = 0;
	key_len = ft_strlen(key);
	while (shell->export[i])
	{
		if (ft_strncmp(shell->export[i], key, key_len) == 0
			&& (shell->export[i][key_len] == '='
			|| shell->export[i][key_len] == '\0'))
		{
			entry = create_export_entry(key, value);
			if (!entry)
				return (1);
			free(shell->export[i]);
			shell->export[i] = entry;
			return (0);
		}
		i++;
	}
	return (1);
}

static int	add_export_value(t_shell *shell,
	char *key, char *value)
{
	char	**new_export;
	char	*entry;
	int		len;

	len = 0;
	while (shell->export[len])
		len++;
	entry = create_export_entry(key, value);
	if (!entry)
		return (1);
	new_export = malloc(sizeof(char *) * (len + 2));
	if (!new_export)
		return (free(entry), 1);
	len = -1;
	while (shell->export[++len])
		new_export[len] = shell->export[len];
	new_export[len++] = entry;
	new_export[len] = NULL;
	free(shell->export);
	shell->export = new_export;
	return (0);
}

int	update_export_value(t_shell *shell, char *key, char *value)
{
	if (!shell || !shell->export || !key)
		return (1);
	if (replace_export_value(shell, key, value) == 0)
		return (0);
	return (add_export_value(shell, key, value));
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
			if (handle_export_with_value(args[i],
					sep, shell) == 1)
				status = 1;
		}
		i++;
	}
	return (status);
}
