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
void	cleanup_shell(t_shell *shell)
{
	free_array(shell->env);
	free_array(shell->export);
}