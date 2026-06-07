#include "../../../../inc/executor.h"
#include "../../../../inc/minishell.h"

int	exec_builtin_with_redir(t_ast_node *node, t_shell *shell)
{
	int	saved_stdout;
	int	saved_stdin;
	int	status;

	saved_stdout = dup(STDOUT_FILENO);
	saved_stdin = dup(STDIN_FILENO);
	if (apply_redirections(node->redir) == -1)
	{
		dup2(saved_stdout, STDOUT_FILENO);
		dup2(saved_stdin, STDIN_FILENO);
		close(saved_stdout);
		close(saved_stdin);
		return (1);
	}
	status = exec_builtin(node, shell);
	dup2(saved_stdout, STDOUT_FILENO);
	dup2(saved_stdin, STDIN_FILENO);
	close(saved_stdout);
	close(saved_stdin);
	return (status);
}
