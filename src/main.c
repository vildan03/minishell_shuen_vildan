#include "../inc/executor.h"
#include "../inc/expander.h"
#include "../inc/minishell.h"
#include "../inc/parser.h"

volatile sig_atomic_t	g_exit_status = 0;

void	expand_entire_tree(t_ast_node *node, char **env, int last_status)
{
	if (node == NULL)
		return ;
	if (node->type == NODE_COMMAND)
		expand_command_args(node, env, last_status);
	expand_entire_tree(node->left, env, last_status);
	expand_entire_tree(node->right, env, last_status);
}

bool	is_whitespaces_only(char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (!ft_isspace(input[i]))
			return (false);
		i++;
	}
	return (true);
}

static void	execute_command(t_shell *shell, t_ast_node *ast_root)
{
	expand_entire_tree(ast_root, shell->env, shell->last_exit_status);
	execution_signals();
	shell->last_exit_status = exec_ast(ast_root, shell);
	interactive_signals();
	printf("[exit status = %d]\n", shell->last_exit_status);
	free_ast(ast_root);
	shell->ast_root = NULL;
}

static void	process_command(t_shell *shell, char *input)
{
	t_token		*token_list;
	t_ast_node	*ast_root;
	int			interactive;

	token_list = NULL;
	ast_root = NULL;
	interactive = isatty(STDIN_FILENO) && isatty(STDOUT_FILENO);
	if (*input && interactive)
		add_history(input);
	token_list = construct_token_list(input, token_list);
	if (!token_list)
		return ;
	shell->token_list = token_list;
	if (check_valid_syntax(token_list) != 0)
	{
		shell->last_exit_status = 2;
		free_token_list(token_list);
		shell->token_list = NULL;
		return ;
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

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	char	*input;
	int		interactive;

	(void)argc;
	(void)argv;
	if (init_shell(&shell, envp))
		return (1);
	interactive = isatty(STDIN_FILENO) && isatty(STDOUT_FILENO);
	while (1)
	{
		interactive_signals();
		if (interactive)
			input = readline("minishell$ ");
		else
			input = readline("");
		if (g_exit_status)
		{
			shell.last_exit_status = g_exit_status;
			g_exit_status = 0;
		}
		if (!input)
		{
			if (interactive)
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
