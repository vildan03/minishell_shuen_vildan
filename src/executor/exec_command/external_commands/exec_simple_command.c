#include "../../../../inc/minishell.h"
#include "../../../../inc/executor.h"
#include <sys/wait.h>

int	exec_external(t_ast_node *node, t_shell *shell)
{
	//write has_pipe, has_redirs...
	return (exec_simple_command(node, shell));
}
static char	*join_cmd_path(char *dir, char *cmd)
{
	char	*tmp;
	char	*full_path;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	full_path = ft_strjoin(tmp, cmd);
	free(tmp);
	return (full_path);
}

static char	*check_paths(char **paths, char *cmd)
{
	char	*full_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		full_path = join_cmd_path(paths[i], cmd);
		if (!full_path)
			return (free_array(paths), NULL);
		if (access(full_path, F_OK) == 0)
		{
			free_array(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_array(paths);
	return (NULL);
}

char	*find_command_path(char *cmd, char **envp)
{
	char	**paths;
	int		i;
 if (!cmd || !envp)
		 return (NULL);
		if (ft_strchr(cmd, '/'))
	return (ft_strdup(cmd));
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	return (check_paths(paths, cmd));
}
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

static void	handle_child_error(char *path, t_ast_node *node, t_shell *shell)
{
	perror(node->args[0]);
	free(path);
	cleanup_shell(shell);
	exit(126);
}

int	exec_simple_command(t_ast_node *node, t_shell *shell)
{
	pid_t	pid;
	int		status;
	char	*path;

	if (!node || !node->args || !node->args[0])
		return (0);
	path = find_command_path(node->args[0], shell->env);
	pid = fork();
	if (pid == -1)
		return (free(path), perror("fork"), 1);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (apply_redirections(node->redir) == -1)
			(cleanup_shell(shell), exit(1));
		exit_exec_error(node->args[0], path, shell);
		execve(path, node->args, shell->env);
		handle_child_error(path, node, shell);
	}
	free(path);
	if (waitpid(pid, &status, 0) == -1)
		return (perror("waitpid"), 1);
	return (get_child_status(status));
}
