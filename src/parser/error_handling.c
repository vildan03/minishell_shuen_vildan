# include "parser.h"

void print_syntax_err(char *error_msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd(" (syntax error)", 2);
}
