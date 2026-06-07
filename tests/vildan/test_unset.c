#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_shell
{
	char	**env;
	char	**export;
}			t_shell;

int			exec_builtin_unset(char **args, t_shell *shell);

static void	print_array(char **arr, char *name)
{
	int	i;

	printf("%s:\n", name);
	i = 0;
	while (arr[i])
	{
		printf("[%d] %s\n", i, arr[i]);
		i++;
	}
	printf("\n");
}

int	main(void)
{
	t_shell shell;
	char *env[] = {strdup("USER=vildan"), strdup("PATH=/usr/bin"),
		strdup("HOME=/home/vildan"), NULL};
	char *export[] = {strdup("USER=vildan"), strdup("PATH=/usr/bin"),
		strdup("HOME=/home/vildan"), strdup("EMPTY"), NULL};

	char *test1[] = {"unset", "PATH", NULL};
	char *test2[] = {"unset", "DOES_NOT_EXIST", NULL};
	char *test3[] = {"unset", "123ABC", NULL};
	char *test4[] = {"unset", "HOME", "USER", NULL};

	shell.env = env;
	shell.export = export;

	printf("=== BEFORE ===\n");
	print_array(shell.env, "ENV");
	print_array(shell.export, "EXPORT");

	printf("=== TEST 1 : unset PATH ===\n");
	printf("status = %d\n\n", exec_builtin_unset(test1, &shell));
	print_array(shell.env, "ENV");
	print_array(shell.export, "EXPORT");

	printf("=== TEST 2 : unset DOES_NOT_EXIST ===\n");
	printf("status = %d\n\n", exec_builtin_unset(test2, &shell));
	print_array(shell.env, "ENV");
	print_array(shell.export, "EXPORT");

	printf("=== TEST 3 : unset 123ABC ===\n");
	printf("status = %d\n\n", exec_builtin_unset(test3, &shell));
	print_array(shell.env, "ENV");
	print_array(shell.export, "EXPORT");

	printf("=== TEST 4 : unset HOME USER ===\n");
	printf("status = %d\n\n", exec_builtin_unset(test4, &shell));
	print_array(shell.env, "ENV");
	print_array(shell.export, "EXPORT");

	return (0);
}