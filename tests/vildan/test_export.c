#include "../../inc/minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argc;
	argv[0] = "export";
	argv[1] = "KEY=VALUE";
	argv[2] = NULL;
	shell.env = copy_envp(envp);
	if (!shell.env)
		return (1);
	shell.last_exit_status = 0;
	if (!exec_builtin_export(argv, shell))
		return (1);
	return (0);
}