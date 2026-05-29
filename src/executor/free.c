#include "../../inc/minishell.h"
#include "../../inc/executor.h"

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
void cleanup_shell(t_shell *shell)
{
    if (shell->ast_root)
        free_ast(shell->ast_root);
    if (shell->token_list)
        free_token_list(shell->token_list);

    free_array(shell->env);
    free_array(shell->export);

    shell->ast_root = NULL;
    shell->token_list = NULL;
}