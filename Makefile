# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/23 15:18:11 by ccavalca          #+#    #+#              #
#    Updated: 2025/12/14 15:06:29 by ccavalca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes -I./libft

SRC_DIR = src
OBJ_DIR = objs
LIBFT_DIR = libft

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
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	@echo "🔗 Linkando $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)
	@echo "✅ $(NAME) compilado com sucesso!"
	
$(LIBFT_A):
	@echo "📚 Compilando Libft..."
	make -C $(LIBFT_DIR) --no-print-directory

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "🧹 Limpando objetos..."
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	@echo "🗑️ Removendo executável..."
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re