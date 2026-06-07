#include "../../inc/executor.h"
#include "../../inc/minishell.h"

int	main(void)
{
	t_shell	shell;
	int		status;

	shell.env = NULL;
	shell.last_exit_status = 0;
	status = exec_builtin_pwd();
	if (status != 0)
		return (printf("FAIL: exec_builtin_pwd returned %d\n", status), 1);
	printf("PASS: exec_builtin_pwd\n");
	return (0);
}
