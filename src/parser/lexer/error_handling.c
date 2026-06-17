#include "parser.h"

void	print_syntax_err(char *error_msg, char *additional_msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(error_msg, 2);
	if (additional_msg != NULL)
	{
		ft_putstr_fd("'", 2);
		ft_putstr_fd(additional_msg, 2);
		ft_putstr_fd("'\n", 2);
	}
}
