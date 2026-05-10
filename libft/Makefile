# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vildan <vildan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 18:09:29 by vikaradu          #+#    #+#              #
#    Updated: 2025/11/23 13:35:20 by vildan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAG = -Wall -Wextra -Werror
NAME = libft.a
RM = rm -f

SRC = ft_atoi.c \
 ft_bzero.c \
 ft_calloc.c \
 ft_isalnum.c \
 ft_isalpha.c \
 ft_isascii.c \
 ft_isdigit.c \
 ft_isprint.c \
 ft_memchr.c \
 ft_memcmp.c \
 ft_memcpy.c \
 ft_memmove.c \
 ft_memset.c \
 ft_split.c \
 ft_strchr.c \
 ft_strdup.c \
 ft_strjoin.c \
 ft_strlcpy.c \
 ft_strlcat.c \
 ft_strlen.c \
 ft_strncmp.c \
 ft_strnstr.c \
 ft_strrchr.c \
 ft_substr.c \
 ft_tolower.c \
 ft_toupper.c \
 ft_strtrim.c \
 ft_itoa.c \
 ft_strmapi.c \
 ft_striteri.c \
 ft_putchar_fd.c \
 ft_putstr_fd.c \
 ft_putendl_fd.c \
 ft_putnbr_fd.c

SRC_BONUS = ft_lstnew_bonus.c \
 ft_lstadd_front_bonus.c \
 ft_lstsize_bonus.c \
 ft_lstadd_back_bonus.c \
 ft_lstlast_bonus.c \
 ft_lstdelone_bonus.c \
 ft_lstclear_bonus.c \
 ft_lstiter_bonus.c \
 ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"

%.o: %.c
	@${CC} $(FLAG) -c $< -o $@

%_bonus.o: %_bonus.c
	@${CC} $(FLAG) -c $< -o $@

bonus: $(OBJ) $(OBJ_BONUS)
	@ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ_BONUS)
	@echo "OBJ and OBJ_BONUS deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all bonus

.PHONY: all, clean, fclean, re