#include "../../inc/executor.h"
#include "../../inc/minishell.h"

static int	restore_redir_fds(int saved_stdout, int saved_stdin, int status)
{
	int	restore_failed;

	restore_failed = 0;
	if (dup2(saved_stdout, STDOUT_FILENO) == -1)
		restore_failed = 1;
	if (dup2(saved_stdin, STDIN_FILENO) == -1)
		restore_failed = 1;
	close(saved_stdout);
	close(saved_stdin);
	if (restore_failed)
		return (perror("dup2"), 1);
	return (status);
}

int	exec_redir_only(t_ast_node *node)
{
	int	saved_stdout;
	int	saved_stdin;

	saved_stdout = dup(STDOUT_FILENO);
	saved_stdin = dup(STDIN_FILENO);
	if (saved_stdout == -1 || saved_stdin == -1)
	{
		if (saved_stdout != -1)
			close(saved_stdout);
		if (saved_stdin != -1)
			close(saved_stdin);
		return (perror("dup"), 1);
	}
	if (apply_redirections(node->redir) == -1)
		return (restore_redir_fds(saved_stdout, saved_stdin, 1));
	return (restore_redir_fds(saved_stdout, saved_stdin, 0));
}
