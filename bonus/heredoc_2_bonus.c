/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vildan <vildan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:51:55 by vikaradu          #+#    #+#             */
/*   Updated: 2026/06/22 14:16:22 by vildan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "executor_bonus.h"
# include "minishell_bonus.h"

static int	write_heredoc_line(int fd, char *line)
{
	if (write(fd, line, ft_strlen(line)) == -1)
		return (perror("write"), 1);
	if (write(fd, "\n", 1) == -1)
		return (perror("write"), 1);
	return (0);
}

void	print_heredoc_warning(char *delimiter)
{
	ft_putstr_fd("minishell: warning: here-document delimited by ", 2);
	ft_putstr_fd("end-of-file (wanted `", 2);
	ft_putstr_fd(delimiter, 2);
	ft_putendl_fd("')", 2);
}

int	handle_heredoc_line(int write_fd, char *line, t_redir *redir,
		t_shell *shell)
{
	char	*content;

	content = line;
	if (!redir->quoted)
		content = expand_heredoc_line(line, shell->env,
				shell->last_exit_status);
	if (!content)
		return (1);
	if (write_heredoc_line(write_fd, content) != 0)
	{
		if (content != line)
			free(content);
		return (1);
	}
	if (content != line)
		free(content);
	return (0);
}

void	write_newline(void)
{
	int	r_val;

	r_val = write(2, "\n", 1);
	(void)r_val;
}

int	process_heredoc(t_redir *redir, t_shell *shell)
{
	if (!redir || redir->type != REDIR_HEREDOC)
		return (-1);
	return (create_heredoc_fd(redir, shell));
}
