# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/19 19:38:06 by mirivera          #+#    #+#              #
#    Updated: 2019/05/01 19:19:24 by mirivera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADERS = ./fillit.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = main.c 

OBJ = main.o

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@$(CC) $(CFLAGS) -I $(HEADERS) -o main.o -c main.c
	@$(CC) $(CFLAGS) -I $(HEADERS) -o fillit $(OBJ) -L libft/ -lft -g

clean:
	@echo 'Removing object files'
	@rm -rf $(OBJ)

fclean: clean
	@echo 'Removing fillit executable'
	@rm -rf fillit

re: fclean all

exe:
	@rm -rf a.out*
	@ls
