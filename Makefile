# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 16:25:09 by jede-ara          #+#    #+#              #
#    Updated: 2023/07/14 15:05:01 by jede-ara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -pthread

SRC = main.c \
		utils/ft_atoi.c \

OBJ = $(SRC:%.c=%.o)

GREEN           :=      \033[1;32m
RED             :=      \033[1;31m
WHITE           :=      \033[1;37m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN) [Success]  Philosophers compilation.$(BOLD)"
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 
	@echo "$(GREEN) [Success] ./philosophers created.$(BOLD)"

clean:
	@rm -rf $(OBJ)
	@echo "$(RED) [Deleting] object files deleted.$(BOLD)"

fclean: clean
	@rm -rf $(NAME) $(OBJ)
	@echo "$(RED) [Deleting] .a deleted.$(BOLD)"

re: fclean all

.SILENT: 

.PHONY: all clean fclean re