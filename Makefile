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

SRCS        = src/main.c \
              src/executor/execute_ast.c \
              src/executor/execute_nods.c \
              src/executor/builtin_utils.c \
              src/executor/builtin_exec.c \
              src/executor/builtin_exec_extra.c \
	      src/parser/parser_main.c \
	      src/parser/error_handling.c \

OBJS        = $(SRCS:.c=.o)
TEST_COMMON = src/executor/execute_ast.c \
              src/executor/execute_nods.c \
              src/executor/builtin_utils.c \
              src/executor/builtin_exec.c \
              src/executor/builtin_exec_extra.c

all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
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

test_is_builtin: $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) tests/vildan/test_is_builtin.c $(TEST_COMMON) $(LIBFT_FLAGS) -lreadline -o tests/vildan/test_is_builtin

test_pwd: $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) tests/vildan/test_pwd.c $(TEST_COMMON) $(LIBFT_FLAGS) -lreadline -o tests/vildan/test_pwd

test_exec_command: $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) tests/vildan/test_exec_command.c $(TEST_COMMON) $(LIBFT_FLAGS) -lreadline -o tests/vildan/test_exec_command

.PHONY: all clean fclean re test_is_builtin test_pwd test_exec_command
