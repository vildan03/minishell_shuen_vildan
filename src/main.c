#include "../inc/minishell.h"
#include "../inc/executor.h"

static char	**copy_envp(char **envp)
{
	char	**copy;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		copy[i] = ft_strdup(envp[i]);
		if (!copy[i])
			return (NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}


static int	init_shell(t_shell *shell, char **envp)
{
	shell->env = copy_envp(envp);
	shell->export = copy_envp(envp);
	shell->last_exit_status = 0;
	if (!shell->env || !shell->export)
		return (1);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell		shell;
	char		*input;
	t_token		*token_list;
	t_ast_node	*ast_root;

	(void)argc;
	(void)argv;
	if (init_shell(&shell, envp))
		return (1);
	while (1)
	{
		token_list = NULL;
		ast_root = NULL;
		input = readline("minishell$ ");
		if (!input)
			break ;
		if (*input)
			add_history(input);
		token_list = construct_token_list(input, token_list);
		if (!token_list)
		{
			free(input);
			continue ;
		}
		if (check_valid_syntax(token_list) != 0)
		{
			shell.last_exit_status = 2;
			free(input);
			free_token_list(token_list);
			continue ;
		}
		ast_root = parse_logic(token_list, NULL);
		if (ast_root)
		{
			shell.last_exit_status = exec_ast(ast_root, &shell);
		//	free_ast(ast_root); write this
		}
		free_token_list(token_list);
		free(input);
	}
	ft_putendl_fd("exit", 1);
	free_array(shell.env);
	free_array(shell.export);
	return (shell.last_exit_status);
}