# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigolon <erigolon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 14:49:32 by erigolon          #+#    #+#              #
#    Updated: 2023/11/08 11:00:06 by erigolon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

SRCS = main.c \
		args_error.c \
		philo_utils.c \
		init.c \
		thread.c \
		routine.c

OBJS = $(SRCS:.c=.o)

OBJ_DIR = objs

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compilando...$(DEFAULT)"

$(NAME): $(addprefix $(OBJ_DIR)/, $(OBJS))
	@$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo "$(GREEN)Programa listo!$(DEFAULT)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Borrando objetos$(DEFAULT)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Borrando programa$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
