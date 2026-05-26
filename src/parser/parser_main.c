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

int main(int argc, char **argv, char **envp)
{
	char *input;
	t_token *token_list;
	t_ast_node *ast_root;
	t_env *env_list;

	(void) argc;
	(void) argv;
	token_list = NULL;
	input = readline("minishell$ ");
	env_list = init_env(envp);
	if(input == NULL)
		return 0;
	token_list = construct_token_list(input, token_list);
	if(token_list == NULL)
		return (free(input), free_env_list(env_list), 1);
	print_tokens(token_list);
	if(check_valid_syntax(token_list) != 0)
		return(free(input), free_token_list(token_list), free_env_list(env_list), 1);
	else
	{
		ast_root = parse_logic(token_list, NULL);

		printf("\n--- AST TREE *BEFORE EXPAND* ---\n");
		print_ast(ast_root, 0);
		printf("-----------------------------------\n");
		expand_entire_tree(ast_root, env_list, 42);
		printf("\n--- AST TREE *AFTER EXPAND* ---\n");
		print_ast(ast_root, 0);
		printf("-----------------------------------\n");

	}
	free(input);
	free_token_list(token_list);
	free_ast(ast_root);
	free_env_list(env_list);

	return 0;
}
