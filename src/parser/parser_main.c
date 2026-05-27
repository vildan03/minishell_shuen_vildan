# include "parser.h"

void expand_entire_tree(t_ast_node *node, t_env *env, int last_status)
{
    if (node == NULL)
        return;

    if (node->type == NODE_COMMAND)
        expand_command_args(node, env, last_status);
    expand_entire_tree(node->left, env, last_status);
    expand_entire_tree(node->right, env, last_status);
}

bool is_whitespaces_only(char *input)
{
	int i;

	i = 0;
	while(input[i] != '\0')
	{
		if(!ft_isspace(input[i]))
			return false;
		i++;
	}
	return true;
}

int main(int argc, char **argv, char **envp)
{
	char *input;
	t_token *token_list;
	t_ast_node *ast_root;
	t_env *env_list;

	(void) argc;
	(void) argv;
	token_list = NULL;
	env_list = init_env(envp);

	while(1)
	{
		input = readline("minishell$ ");
		if(input == NULL)
			break;
		if(*input && is_whitespaces_only(input) == false)
 		{
			add_history(input);
			token_list = construct_token_list(input, token_list);
			if(token_list && check_valid_syntax(token_list) == 0)
			{
				ast_root = parse_logic(token_list, NULL);

				printf("\n--- AST TREE *BEFORE EXPAND* ---\n");
				print_ast(ast_root, 0);
				printf("-----------------------------------\n");
				expand_entire_tree(ast_root, env_list, 42);
				printf("\n--- AST TREE *AFTER EXPAND* ---\n");
				print_ast(ast_root, 0);
				printf("-----------------------------------\n");
				free_ast(ast_root);
			}
			free_token_list(token_list);
		}
		free(input);
	}
	free_env_list(env_list);

	return 0;
}
