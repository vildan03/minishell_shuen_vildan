
#include "executor.h"
#include "minishell.h"

static void	exit_pipe_error(int fd[2], t_shell *shell)
{
	perror("dup2");
	close(fd[0]);
	close(fd[1]);
	cleanup_shell(shell);
	exit(1);
}

static void	setup_pipe_child(t_ast_node *node, t_shell *shell, int fd[2],
		int is_left)
{
	t_ast_node	*child_node;
	int			status;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (is_left)
		child_node = node->left;
	else
		child_node = node->right;
	if (is_left)
	{
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			exit_pipe_error(fd, shell);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			exit_pipe_error(fd, shell);
		close(fd[0]);
	}
	if (child_node && child_node->type == NODE_COMMAND && child_node->args
		&& child_node->args[0] && !is_builtin(child_node->args[0]))
		exec_external_child(child_node, shell);
	status = exec_ast(child_node, shell);
	cleanup_shell(shell);
	exit(status);
}

static int	fork_pipe_child(t_ast_node *node, t_shell *shell, int fd[2],
		int is_left)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		perror("fork");
		return (-1);
	}
	if (pid == 0)
		setup_pipe_child(node, shell, fd, is_left);
	return (pid);
}

static int	wait_pipe_children(pid_t left_pid, pid_t right_pid)
{
	int	status;

	if (waitpid(left_pid, NULL, 0) == -1)
		return (perror("waitpid"), 1);
	if (waitpid(right_pid, &status, 0) == -1)
		return (perror("waitpid"), 1);
	return (get_child_status(status));
}

int	exec_pipe(t_ast_node *node, t_shell *shell)
{
	int		fd[2];
	pid_t	left_pid;
	pid_t	right_pid;

	if (pipe(fd) == -1)
		return (perror("pipe"), 1);
	left_pid = fork_pipe_child(node, shell, fd, 1);
	if (left_pid == -1)
		return (1);
	right_pid = fork_pipe_child(node, shell, fd, 0);
	if (right_pid == -1)
	{
		waitpid(left_pid, NULL, 0);
		return (1);
	}
	close(fd[0]);
	close(fd[1]);
	return (wait_pipe_children(left_pid, right_pid));
}
