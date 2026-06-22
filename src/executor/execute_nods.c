/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_nods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:53:05 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 11:51:27 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "expander.h"
#include "minishell.h"

int	exec_command(t_ast_node *node, t_shell *shell)
{
	if (!node)
		return (1);
	if ((!node->args || !node->args[0]) && node->redir)
		return (exec_redir_only(node, shell));
	if (!node->args || !node->args[0])
		return (0);
	if (is_builtin(node->args[0]))
		return (exec_builtin_with_redir(node, shell));
	return (exec_simple_command(node, shell));
}
