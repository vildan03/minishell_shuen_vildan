# include "parser.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

void	ft_putstr_fd(char *s, int fd)
{
	(void)write(fd, s, ft_strlen(s));
}

void print_syntax_err(char *error_msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd(" (syntax error)", 2);
}

int which_token_type(char *input, int *i)
{
	int type;

	type = INT_MAX;
	if(input[*i] == '>' && input[*i + 1] == '>')
	{
		type = TOKEN_APPEND;
		(*i)++;
	}
	else if(input[*i] == '<' && input[*i + 1] == '<')
	{
		type = TOKEN_HEREDOC;
		(*i)++;
	}
	else if (input[*i] == '>')
		type = REDIR_OUT;
	else if (input[*i] == '<')
		type = TOKEN_REDIR_IN;
	else if (input[*i] == '|')
		type = TOKEN_PIPE;
	else
		type = TOKEN_WORD;
	return type;
}

bool ft_isspace(char a)
{
	if(a == ' ' || (a >= '\t' && a <= '\r'))
		return true;
	return false;
}

t_token *construct_token_list(char *input)
{
	int i;
	int type;

	i = 0;
	if(!input)
		return NULL;
	while(input[i] != '\0')
	{
		while(ft_isspace(input[i]) == true)
			i++;
		type = which_token_type(input, &i);
		if(type == INT_MAX)
			return (print_syntax_err("token type not found"), NULL);
		i++;
	}
	if(input[i] == '\0')
		type = TOKEN_EOF;
	return NULL;
}

int main(void)
{
	char *input;
	t_token *token_arr;

	// Do we have to do anything when input is NULL?
	input = readline("minishell$ ");
	printf("%s\n", input);

	token_arr = construct_token_arr(input);
	if(token_arr == NULL)
		return 1;


	free(input);

	return 0;
}
