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

SRCS        = main.c \
              src/executor/execute_ast.c \
              src/executor/execute_nods.c \
              src/executor/builtin_commands/utils.c \
              src/executor/builtin_commands/execute.c \
              src/executor/builtin_commands/env.c \
              src/executor/builtin_commands/cd.c \
              src/executor/builtin_commands/exit.c \
              src/executor/builtin_commands/export_utils.c \
              src/executor/builtin_commands/unset.c \
              src/executor/builtin_commands/env_utils.c \
              src/executor/builtin_commands/env_utils_2.c \

OBJS        = $(SRCS:.c=.o)

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

test_unset: $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) \
		tests/vildan/test_unset.c \
		src/executor/builtin_commands/builtin_unset.c \
		$(LIBFT_FLAGS) -lreadline \
		-o tests/vildan/test_unset

.PHONY: all clean fclean re
