# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/23 15:18:11 by ccavalca          #+#    #+#              #
#    Updated: 2025/12/14 14:14:01 by ccavalca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./Libft -I./ft_printf

LIBFT_DIR = Libft/
PRINTF_DIR = ft_printf/

SRC =	push_swap.c \
		clean_and_error.c \
		commands_all.c \
		commands_a.c \
		commands_b.c \
		commands_utils.c \
		stack_utils.c \
		validation.c \
		validation_utils.c \
		sort.c \
		sort_utils.c \
		radix_sort.c \

LIBFT_A = $(LIBFT_DIR)/libft.a
PRINTF_A = $(PRINTF_DIR)/libftprintf.a
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT_A) $(PRINTF_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(PRINTF_A) -o $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(PRINTF_A):
	make -C $(PRINTF_DIR)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(PRINTF_A) $(LIBFT_A) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT_A) $(PRINTF_A) -o $(NAME_BONUS)

re: fclean all

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

.PHONY: all clean fclean re bonus