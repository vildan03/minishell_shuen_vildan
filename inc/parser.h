#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

// LEXER ---------------------------------------------------------
// error_handling.c
void					print_syntax_err(char *error_msg, char *additional_msg);

// construct_token_list.c
t_token					*create_new_token(void);
int						get_word_value(char *input, int *i, t_token *token);
int						get_token_type(char *input, int i);
int						get_token_value(char *inpit, int *i, t_token *token);
t_token					*construct_token_list(char *inpit, t_token *token_list);

// token_list_utils.c
bool					ft_isspace(char a);
bool					is_word(char x);
void					free_token_list(t_token *token);

// SYNTAX_CHECKER ---------------------------------------------------
// check_syntax.c
int						check_valid_syntax(t_token *token);

// check_syntax_utils.c
bool					is_redir(int x);
bool					is_binary_op(int type);

// BUILD_AST --------------------------------------------------------
// build_ast_utils.c
void					extract_redirections(t_ast_node *node, t_token *start,
							t_token *end);
int						count_args(t_token *start, t_token *end);
char					**build_args_array(t_token *start, t_token *end);
int						create_and_append_redir(t_ast_node *node,
							t_token *current);

// build_ast_utils_2.c
t_token					*find_top_op(t_token *start, t_token *end, int op1,
							int op2);
t_token					*find_matching_paren(t_token *start, t_token *end);
void					append_redir_node(t_redir **head, t_redir *new_node);
t_ast_node				*create_ast_node(t_node_type type);
int						is_redir_ast(int type);
t_redir_type			translate_token_to_redir(t_token_type type);

// build_ast.c
t_ast_node				*parse_command(t_token *start, t_token *end);
t_ast_node				*parse_element(t_token *start, t_token *end);
t_ast_node				*parse_pipe(t_token *start, t_token *end);
t_ast_node				*parse_logic(t_token *start, t_token *end);

// free_ast.c
void					free_string_array(char **arr);
void					free_redir(t_redir *head);
void					free_ast(t_ast_node *node);

#endif
