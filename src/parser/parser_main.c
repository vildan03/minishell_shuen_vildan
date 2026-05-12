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

void get_word_value(char *input, int *i, t_token *token)
{
	int in_quotes;
	int length;
	int initial_i;

	in_quotes = 0;
	length = 0;
	initial_i = *i;
	while(input[*i] != '\0')
	{
		if(in_quotes == 0 && (input[*i] == '\t' || input[*i] == ' ' || input[*i] == '|' || input[*i] == '<' || input[*i] == '>'))
			break;
		if(input[*i] == '"' || input[*i] == '\'')
		{
			if(in_quotes == 0)
				in_quotes = input[*i];
			else if(in_quotes == input[*i])
				in_quotes = 0;
		}
		length++;
		(*i)++;
	}
	token->value = ft_substr(input, initial_i, length);
}

int get_token_type(char *input, int i)
{
	int type;

	type = INT_MAX;
	if(input[i] == '>' && input[i + 1] == '>')
		type = TOKEN_APPEND;
	else if(input[i] == '<' && input[i + 1] == '<')
		type = TOKEN_HEREDOC;
	else if (input[i] == '>')
		type = TOKEN_REDIR_OUT;
	else if (input[i] == '<')
		type = TOKEN_REDIR_IN;
	else if (input[i] == '|')
		type = TOKEN_PIPE;
	else
		type = TOKEN_WORD;
	return type;
}

void get_token_value(char *input, int *i, t_token *token)
{
	if(token->type == TOKEN_APPEND || token->type == TOKEN_HEREDOC)
	{
		token->value = ft_substr(input, *i, 2);
		*i += 2;
	}
	else if(token->type == TOKEN_REDIR_IN || token->type == TOKEN_REDIR_OUT || token->type == TOKEN_PIPE)
	{
		token->value = ft_substr(input, *i, 1);
		(*i)++;
	}
	else if(token->type == TOKEN_WORD)
		get_word_value(input, i, token);
}

bool ft_isspace(char a)
{
	if(a == ' ' || (a >= '\t' && a <= '\r'))
		return true;
	return false;
}

t_token *create_new_token(void)
{
	t_token *new_token;

	new_token = malloc(sizeof(*new_token));
	if(!new_token)
		return NULL;
	new_token->type = INT_MAX;
	new_token->value = NULL;
	new_token->next = NULL;
	return new_token;
}

t_token *construct_token_list(char *input, t_token *token_list)
{
	int i;
	t_token *current;

	i = 0;
	if(!input)
		return NULL;
	token_list = create_new_token();
	current = token_list;
	while(input[i] != '\0')
	{
		while(ft_isspace(input[i]))
			i++;
		if(input[i] == '\0')
			break;
		current->type = get_token_type(input, i);
		if(current->type == INT_MAX)
			return (print_syntax_err("token type not found"), NULL);
		get_token_value(input, &i, current);
		current->next = create_new_token();
		current = current->next;
		if(input[i] == '\0')
			break;
	}
	if(input[i] == '\0')
		current->type = TOKEN_EOF;
	return token_list;
}

void print_tokens(t_token *token_list)
{
	t_token *current;

	current = token_list;
	while(current->type != TOKEN_EOF)
	{
		printf("%d = %s\n", current->type, current->value);
		current = current->next;
	}
}

int main(void)
{
	char *input;
	t_token *token_list;

	token_list = NULL;
	// Do we have to do anything when input is NULL?
	input = readline("minishell$ ");
	printf("%s\n", input);
	if(input == NULL)
		return 0;

	token_list = construct_token_list(input, token_list);
	if(token_list == NULL)
		return 1;
	print_tokens(token_list);

	free(input);

	return 0;
}
