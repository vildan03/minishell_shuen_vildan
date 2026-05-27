#include "../inc/minishell.h"
#include "../inc/executor.h"

static void	execute_command(t_shell *shell, t_ast_node *ast_root)
{
	execution_signals();
	shell->last_exit_status = exec_ast(ast_root, shell);
	interactive_signals();
	printf("[exit status = %d]\n", shell->last_exit_status);
	/* free_ast(ast_root); */
}

static void	process_command(t_shell *shell, char *input)
{
	t_token		*token_list;
	t_ast_node	*ast_root;

	token_list = NULL;
	ast_root = NULL;
	if (*input)
		add_history(input);
	token_list = construct_token_list(input, token_list);
	if (!token_list)
		return ;
	if (check_valid_syntax(token_list) != 0)
	{
		shell->last_exit_status = 2;
		free_token_list(token_list);
		return ;
	}
	ast_root = parse_logic(token_list, NULL);
	if (ast_root)
		execute_command(shell, ast_root);
	free_token_list(token_list);
}
int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	char	*input;

	(void)argc;
	(void)argv;
	if (init_shell(&shell, envp))
		return (1);
	while (1)
	{
		interactive_signals();
		input = readline("minishell$ ");
		if (g_exit_status)
		{
				shell.last_exit_status = g_exit_status;
				g_exit_status = 0;
		}
		if (!input)
		{
			ft_putendl_fd("exit", 1);
			break ;
		}
		process_command(&shell, input);
		free(input);
	}
	free_array(shell.env);
	free_array(shell.export);
	return (shell.last_exit_status);
}
