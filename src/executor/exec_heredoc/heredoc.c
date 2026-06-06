#include "../../inc/minishell.h"
#include "../../inc/executor.h"

int	has_heredoc(t_redir *redir)
{
	while (redir)
	{
		if (redir->type == REDIR_HEREDOC)
			return (1);
		redir = redir->next;
	}
	return (0);
}

int	process_heredoc(t_redir *redir)
{
	(void)redir;
	return (0);
}
