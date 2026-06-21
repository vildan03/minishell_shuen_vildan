NAME        = minishell

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f

SRC_DIR     = src
INC_DIR     = inc
LIBFT_DIR   = libft

LIBFT       = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
INCLUDES    = -I$(INC_DIR) -I$(LIBFT_DIR)
LIBFT_SRCS  = $(wildcard $(LIBFT_DIR)/*.c)
LIBFT_HDRS  = $(wildcard $(LIBFT_DIR)/*.h)

SRCS		= src/main/main.c \
					src/main/main_helpers.c \
					src/main/main_input.c \
					src/main/main_loop.c \
			  src/executor/execute_ast.c \
			  src/executor/free.c \
			  src/executor/execute_nods.c \
			  src/executor/exec_redir_only.c \
			  src/executor/exec_command//builtin_commands/utils.c \
			  src/executor/exec_command/builtin_commands/execute.c \
			  src/executor/exec_command/builtin_commands/execute_2.c \
			  src/executor/exec_command/builtin_commands/write.c \
			  src/executor/exec_command/builtin_commands/cd.c \
			  src/executor/exec_command/builtin_commands/exit.c \
			  src/executor/exec_command/builtin_commands/exit_2.c \
			  src/executor/exec_command/builtin_commands/export.c \
			  src/executor/exec_command/builtin_commands/export_utils.c \
			  src/executor/exec_command/builtin_commands/unset.c \
			  src/executor/exec_command/builtin_commands/env_utils.c \
			  src/executor/exec_command/external_commands/exec_command_path.c \
			  src/executor/exec_command/external_commands/exec_simple_command.c \
			  src/executor/exec_command/external_commands/redirection.c \
			  src/executor/exec_command/external_commands/error_exit.c \
			  src/executor/exec_pipe/pipe.c \
			  src/executor/exec_pipe/pipe_2.c \
			  src/executor/exec_heredoc/heredoc.c \
			  src/executor/exec_heredoc/heredoc_expand.c \
			  src/executor/exec_heredoc/heredoc_fds.c \
			  src/parser/ast_tools/build_ast_utils.c \
			  src/parser/ast_tools/build_ast_utils_2.c \
			  src/parser/ast_tools/build_ast_utils_3.c \
			  src/parser/ast_tools/build_ast.c \
			  src/parser/ast_tools/free_ast.c \
			  src/parser/lexer/build_token_list.c \
			  src/parser/lexer/error_handling.c \
			  src/parser/lexer/token_list_utils.c \
			  src/expander/expander_utils.c \
			  src/expander/expander_utils_2.c \
			  src/expander/expander.c \
			  src/expander/expander_2.c \
			  src/expander/wildcards_utils.c \
			  src/expander/wildcards_utils_2.c \
			  src/parser/syntax_checker/check_syntax_utils.c \
			  src/parser/syntax_checker/check_syntax.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT): $(LIBFT_SRCS) $(LIBFT_HDRS) $(LIBFT_DIR)/Makefile
	@echo "Compiling libft..."
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) -lreadline -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	@make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	@echo "Cleaning executable..."
	@make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
