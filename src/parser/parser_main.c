# include "parser.h"

int main(void)
{
	char *input;
	t_token *token_list;
	t_ast_node *ast_root;

	token_list = NULL;
	input = readline("minishell$ ");
	printf("%s\n", input);
	if(input == NULL)
		return 0;

	token_list = construct_token_list(input, token_list);
	if(token_list == NULL)
		return 1;
	print_tokens(token_list);
	if(check_valid_syntax(token_list) != 0)
		return(free(input), free_token_list(token_list), 1);
	else
	{
		ast_root = parse_logic(token_list, NULL);

		printf("\n--- AST TREE ---\n");
		print_ast(ast_root, 0);
		printf("\n");
	}
	free(input);

	return 0;
}
