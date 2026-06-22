/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vikaradu <vikaradu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:53:09 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 10:53:10 by vikaradu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor_bonus.h"
#include "minishell_bonus.h"
#include "parser_bonus.h"

void	free_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static void	reset_shell_state(t_shell *shell)
{
	shell->env = NULL;
	shell->export = NULL;
	shell->current_input = NULL;
	shell->ast_root = NULL;
	shell->token_list = NULL;
}

void	cleanup_process_state(t_shell *shell, t_ast_node *ast_root,
		t_token *token_list)
{
	if (ast_root)
		free_ast(ast_root);
	if (token_list)
		free_token_list(token_list);
	free_array(shell->env);
	free_array(shell->export);
	free(shell->current_input);
	reset_shell_state(shell);
}

void	cleanup_shell(t_shell *shell)
{
	cleanup_process_state(shell, shell->ast_root, shell->token_list);
}
