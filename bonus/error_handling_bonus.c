/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:54:10 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 10:54:11 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parser_bonus.h"

static void	print_syntax_prefix(void)
{
	if (isatty(STDIN_FILENO) && isatty(STDERR_FILENO))
		ft_putstr_fd("minishell: ", 2);
	else
		ft_putstr_fd("minishell: line 1: ", 2);
}

void	print_syntax_err(char *error_msg, char *additional_msg)
{
	print_syntax_prefix();
	ft_putstr_fd(error_msg, 2);
	if (additional_msg != NULL)
	{
		ft_putstr_fd("`", 2);
		ft_putstr_fd(additional_msg, 2);
		ft_putstr_fd("'", 2);
	}
	ft_putstr_fd("\n", 2);
}
