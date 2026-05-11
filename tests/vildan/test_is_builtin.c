#include "../../inc/minishell.h"
#include "../../inc/executor.h"

int	main(void)
{
	if (!is_builtin("pwd"))
		return (printf("FAIL: pwd should be builtin\n"), 1);
	if (!is_builtin("echo"))
		return (printf("FAIL: echo should be builtin\n"), 1);
	if (is_builtin("ls"))
		return (printf("FAIL: ls should not be builtin\n"), 1);
	printf("PASS: is_builtin\n");
	return (0);
}
