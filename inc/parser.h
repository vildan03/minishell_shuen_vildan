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
   TOKEN_AND,
   TOKEN_OR,
   TOKEN_LEFT_PAREN,
   TOKEN_RIGHT_PAREN,
   TOKEN_EOF
} t_token_type;

typedef struct s_token {
   int type;
   char *value;
   struct s_token *next;
} t_token;

// LEXER ---------------------------------------------------------
// error_handling.c
void print_syntax_err(char *error_msg, char *additional_msg);

// construct_token_list.c
t_token *create_new_token(void);
int  get_word_value(char *input, int *i, t_token *token);
int get_token_type(char *input, int i);
int get_token_value(char *inpit, int *i, t_token *token);
t_token *construct_token_list(char *inpit, t_token *token_list);

// token_list_utils.c
bool ft_isspace(char a);
bool is_word(char x);
void free_token_list(t_token *token);
void print_tokens(t_token *token_list); // REMOVE??

// SYNTAX_CHECKER ---------------------------------------------------
// check_syntax.c
int check_valid_syntax(t_token *token);

// check_syntax_utils.c
bool is_redir(int x);
bool is_binary_op(int type);

// BUILD_AST --------------------------------------------------------
// print_ast.c
void print_spaces(int depth);
void print_ast(t_ast_node *node , int depth);

// build_ast_utils.c
t_token *find_last_op(t_token *start, t_token *end, int first_token, int second_token);
t_token *get_last_token(t_token *start, t_token *end);
void extract_redirections(t_ast_node *node, t_token *start, t_token *end);
int count_args(t_token *start, t_token *end);
char **build_args_array(t_token *start, t_token *end);

// build_ast_utils_2.c
void append_redir_node(t_redir **head, t_redir *new_node);
t_ast_node *create_ast_node(t_node_type type);

// build_ast.c
t_ast_node *parse_command(t_token *start, t_token *end);
t_ast_node *parse_pipe(t_token *start, t_token *end);
t_ast_node *parse_logic(t_token *start, t_token *end);

// free_ast.c
void free_string_array(char **arr);
void free_redir(t_redir *head);
void free_ast(t_ast_node *node);

#endif
