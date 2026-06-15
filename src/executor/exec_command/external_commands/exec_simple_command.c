#include "../../../../inc/executor.h"
#include "../../../../inc/expander.h"
#include "../../../../inc/minishell.h"
#include <sys/wait.h>

int	get_child_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGQUIT)
			ft_putendl_fd("Quit (core dumped)", 2);
		return (128 + WTERMSIG(status));
	}
	return (1);
}

static void	handle_child_error(char *path, t_ast_node *node, t_shell *shell,
		t_ast_node *ast_root, t_token *token_list)
{
	perror(node->args[0]);
	free(path);
	cleanup_process_state(shell, ast_root, token_list);
	exit(126);
}

static void	run_child_command(t_ast_node *node, t_shell *shell, char *path,
		t_ast_node *ast_root, t_token *token_list)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	free(shell->current_input);
	shell->current_input = NULL;
	free(path);
	if (apply_redirections(node->redir) == -1)
		(cleanup_process_state(shell, ast_root, token_list), exit(1));
	path = find_command_path(node->args[0], shell->env);
	execve(path, node->args, shell->env);
	handle_child_error(path, node, shell, ast_root, token_list);
}

static int	wait_simple_command(pid_t pid)
{
	int	status;

	if (waitpid(pid, &status, 0) == -1)
		return (perror("waitpid"), 1);
	return (get_child_status(status));
}

int	exec_simple_command(t_ast_node *node, t_shell *shell)
{
	pid_t		pid;
	int			path_status;
	char		*path;
	t_ast_node	*ast_root;
	t_token		*token_list;

	if (!node || !node->args || !node->args[0])
		return (0);
	ast_root = shell->ast_root;
	token_list = shell->token_list;
	path = find_command_path(node->args[0], shell->env);
	path_status = validate_exec_path(node->args[0], path);
	if (path_status != 0)
		return (free(path), path_status);
	pid = fork();
	if (pid == -1)
		return (free(path), perror("fork"), 1);
	if (pid == 0)
		run_child_command(node, shell, path, ast_root, token_list);
	free(path);
	return (wait_simple_command(pid));
}
