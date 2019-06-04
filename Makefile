# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/19 19:38:06 by mirivera          #+#    #+#              #
#    Updated: 2019/06/03 20:03:08 by mirivera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

HEADERS = ./fillit.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = main.c validate.c solve.c

OBJ = main.o validate.o solve.o

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@$(CC) $(CFLAGS) -I $(HEADERS) -o main.o -c main.c
	@$(CC) $(CFLAGS) -I $(HEADERS) -o validate.o -c validate.c
	@$(CC) $(CFLAGS) -I $(HEADERS) -o solve.o -c solve.c
	@$(CC) $(CFLAGS) -I $(HEADERS) -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	@rm -rf $(OBJ)
	@make -C libft clean

fclean:	clean
	@rm -rf $(NAME)
	@make -C libft fclean

re:	fclean all