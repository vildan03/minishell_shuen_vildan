#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"
# include "limits.h"
# include "stdbool.h"

typedef enum s_token_type {
   TOKEN_WORD,
   TOKEN_PIPE,
   TOKEN_REDIR_IN,
   TOKEN_REDIR_OUT,
   TOKEN_HEREDOC,
   TOKEN_APPEND,
   TOKEN_EOF
} t_token_type;

typedef struct s_token {
   int type;
   char *value;
   struct s_token *next;
} t_token;

// error_handling.c
void ft_putstr_fd(char *s, int fd);
void print_syntax_err(char *error_msg);

#endif
