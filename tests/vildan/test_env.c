#include <stdio.h>
#include <stdlib.h>
#include "../../inc/minishell.h"
#include "../../inc/executor.h"

static int	test_env_display(void)
{
	t_shell	shell;
	char	*args[2];
	char	*fake_env[3];
	int		status;

	printf("\n=== Test: env display ===\n");
	args[0] = "env";
	args[1] = NULL;
	fake_env[0] = "USER=vildan";
	fake_env[1] = "HOME=/home/vildan";
	fake_env[2] = NULL;
	shell.env = fake_env;
	shell.last_exit_status = 0;
	status = exec_builtin_env(args, &shell);
	if (status != 0)
		return (printf("FAIL: exec_builtin_env returned %d\n", status), 1);
	printf("PASS: env display\n");
	return (0);
}

static int	test_add_env_value(void)
{
	t_shell	shell;
	char	*env[3] = {"USER=vildan", "HOME=/home/vildan", NULL};
	char	**envp;
	int		i;

	printf("\n=== Test: add env value ===\n");
	envp = malloc(sizeof(char *) * 3);
	for (i = 0; i < 3; i++)
		envp[i] = env[i];
	shell.env = envp;
	
	if (update_env_value(&shell, "TEST_VAR", "test_value") != 0)
		return (printf("FAIL: update_env_value\n"), 1);
	if (!get_env_value(shell.env, "TEST_VAR"))
		return (printf("FAIL: TEST_VAR not added\n"), 1);
	if (!get_env_value(shell.env, "USER"))
		return (printf("FAIL: USER lost\n"), 1);
	
	printf("PASS: add env value\n");
	free(shell.env);
	return (0);
}

int	main(void)
{
	int	result;

	result = test_env_display();
	if (result != 0)
		return (1);
	
	result = test_add_env_value();
	if (result != 0)
		return (1);
	
	printf("\n=== All tests passed ===\n");
	return (0);
}
