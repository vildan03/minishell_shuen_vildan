//#include "inc/minishell.h"
//#include "inc/executor.h"

//static char	**copy_envp(char **envp)
//{
	//char	**copy;
	//int		i;

	//i = 0;
	//while (envp[i])
		//i++;
	//copy = malloc(sizeof(char *) * (i + 1));
	//if (!copy)
		//return (NULL);
	//i = 0;
	//while (envp[i])
	//{
		//copy[i] = ft_strdup(envp[i]);
		//i++;
	//}
	//copy[i] = NULL;
	//return (copy);
//}

//static void	free_array(char **arr)
//{
	//int	i;

	//if (!arr)
		//return ;
	//i = 0;
	//while (arr[i])
		//free(arr[i++]);
	//free(arr);
//}
//int	main(int argc, char **argv, char **envp)
//{
	//t_shell		shell;
	//t_ast_node	*ast;
	//char		*line;

	//(void)argc;
	//(void)argv;
	//shell.env = copy_envp(envp);
	//shell.export = copy_envp(envp);
	//shell.last_exit_status = 0;
	//while (1)
	//{
		//line = readline("minishell$ ");
		//if (!line)
			//break ;
		//if (*line)
			//add_history(line);
		//ast = parse_line(line, &shell); //change the name accordingly with parser
		//free(line);
		//if (ast)
		//{
			//shell.last_exit_status = exec_ast(ast, &shell);
			//free_ast(ast);
		//}
	//}
	//return (0);
//}