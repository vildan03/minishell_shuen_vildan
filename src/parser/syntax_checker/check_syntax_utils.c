# include "parser.h"

bool is_binary_op(int type)
{
	if(type == TOKEN_OR || type == TOKEN_AND || type == TOKEN_PIPE)
		return true;
	return false;
}

bool is_redir(int x)
{
	if(x == TOKEN_REDIR_IN || x == TOKEN_REDIR_OUT || x == TOKEN_HEREDOC || x == TOKEN_APPEND)
		return true;
	return false;
}
