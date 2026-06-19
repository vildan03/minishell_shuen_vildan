#include "executor.h"
#include "expander.h"
#include "minishell.h"
#include "parser.h"

void	expand_entire_tree(t_ast_node *node, char **env, int last_status)
{
	if (node == NULL)
		return ;
	if (node->type == NODE_COMMAND)
		expand_command_args(node, env, last_status);
	expand_entire_tree(node->left, env, last_status);
	expand_entire_tree(node->right, env, last_status);
}

static void	cleanup_syntax_error(t_shell *shell, t_token *token_list)
{
	shell->last_exit_status = 2;
	free_token_list(token_list);
	shell->token_list = NULL;
}

static void	print_syntax_input(char *input, int interactive)
{
	if (interactive || !input)
		return ;
	ft_putstr_fd("minishell: line 1: ", 2);
	ft_putstr_fd("`", 2);
	ft_putstr_fd(input, 2);
	ft_putendl_fd("'", 2);
}

static void	execute_command(t_shell *shell, t_ast_node *ast_root)
{
	expand_entire_tree(ast_root, shell->env, shell->last_exit_status);
	execution_signals();
	shell->last_exit_status = exec_ast(ast_root, shell);
	interactive_signals();
	free_ast(ast_root);
	shell->ast_root = NULL;
}

void	process_command(t_shell *shell, char *input, int interactive)
{
	t_token		*token_list;
	t_ast_node	*ast_root;

	if (*input && interactive)
		add_history(input);
	token_list = construct_token_list(input, NULL);
	if (!token_list)
		return ;
	shell->token_list = token_list;
	if (check_valid_syntax(token_list) != 0)
	{
		print_syntax_input(input, interactive);
		return (cleanup_syntax_error(shell, token_list));
	}
	ast_root = parse_logic(token_list, NULL);
	if (ast_root)
	{
		shell->ast_root = ast_root;
		execute_command(shell, ast_root);
	}
	free_token_list(token_list);
	shell->token_list = NULL;
}
