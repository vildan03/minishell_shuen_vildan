/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:54:18 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 10:54:19 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

bool	is_binary_op(int type)
{
	if (type == TOKEN_OR || type == TOKEN_AND || type == TOKEN_PIPE)
		return (true);
	return (false);
}

bool	is_redir(int x)
{
	if (x == TOKEN_REDIR_IN || x == TOKEN_REDIR_OUT || x == TOKEN_HEREDOC
		|| x == TOKEN_APPEND)
		return (true);
	return (false);
}
