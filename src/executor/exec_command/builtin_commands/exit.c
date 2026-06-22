/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:49:53 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 10:49:54 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "executor.h"
#include "minishell.h"

static int	is_numeric(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	print_numeric_error(char *arg)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putendl_fd(": numeric argument required", 2);
}

static int	will_overflow(long long result, int digit, int sign)
{
	if (sign == 1)
		return (result > (LLONG_MAX - digit) / 10);
	return (-result < (LLONG_MIN + digit) / 10);
}

static int	parse_exit_code(char *str, long long *value)
{
	int			i;
	int			sign;
	long long	result;

	if (!is_numeric(str))
		return (1);
	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (will_overflow(result, str[i] - '0', sign))
			return (1);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	*value = result * sign;
	return (0);
}

int	handle_exit_arg(char **args, t_shell *shell, long long *parsed_value)
{
	if (parse_exit_code(args[1], parsed_value) != 0)
	{
		print_numeric_error(args[1]);
		shell->last_exit_status = 2;
		return (2);
	}
	if (args[2])
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		shell->last_exit_status = 1;
		return (1);
	}
	return (0);
}
