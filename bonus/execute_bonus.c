/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:49:48 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 10:49:49 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "executor_bonus.h"
# include "minishell_bonus.h"

int	exec_builtin(t_ast_node *node, t_shell *shell)
{
	if (!node || !node->args || !node->args[0])
		return (1);
	if (ft_strncmp(node->args[0], "pwd", 4) == 0)
		return (exec_builtin_pwd(shell));
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
		return (exec_builtin_exit(node->args, shell, -1, -1));
	if (ft_strncmp(node->args[0], ":", 2) == 0)
		return (0);
	if (ft_strncmp(node->args[0], ":", 2) == 0)
		return (0);
	if (ft_strncmp(node->args[0], ".", 2) == 0)
		return (ft_putendl_fd("minishell: .: filename argument required", 2),
			ft_putendl_fd(".: usage: . filename [arguments]", 2), 2);
	return (1);
}

int	exec_builtin_echo(char **args, t_shell *shell)
{
	int	i;
	int	newline;

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
		if (write_builtin_str(args[i], "echo") != 0)
			return (1);
		if (args[i + 1] && write_builtin_char(' ', "echo") != 0)
			return (1);
		i++;
	}
	if (newline && write_builtin_char('\n', "echo") != 0)
		return (1);
	return (0);
}

int	exec_builtin_env(char **args, t_shell *shell)
{
	int		i;
	char	*path;

	if (!shell || !shell->env)
		return (1);
	if (args[1])
		return (print_env_error(args[1]));
	path = find_command_path("env", shell->env);
	i = 0;
	while (shell->env[i])
	{
		if (ft_strncmp(shell->env[i], "_=", 2) == 0 && path)
		{
			if (write_builtin_str("_=", "env") != 0
				|| write_builtin_str(path, "env") != 0
				|| write_builtin_char('\n', "env") != 0)
				return (free(path), 125);
		}
		else if (write_builtin_str(shell->env[i], "env") != 0
			|| write_builtin_char('\n', "env") != 0)
			return (free(path), 125);
		i++;
	}
	return (free(path), 0);
}

static int	check_export_option(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (args[i][0] == '-' && args[i][1] != '\0')
		{
			ft_putstr_fd("minishell: export: -", 2);
			ft_putchar_fd(args[i][1], 2);
			ft_putendl_fd(": invalid option", 2);
			return (2);
		}
		i++;
	}
	return (0);
}

int	exec_builtin_export(char **args, t_shell *shell)
{
	char	*sep;
	int		i;
	int		status;

	if (!args[1])
		return (print_export(shell));
	status = check_export_option(args);
	if (status != 0)
		return (status);
	i = 0;
	while (args[++i])
	{
		sep = ft_strchr(args[i], '=');
		if (!sep && handle_export_no_value(args[i], shell) == 1)
			status = 1;
		else if (sep && handle_export_with_value(args[i], sep, shell) == 1)
			status = 1;
	}
	return (status);
}
