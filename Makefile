# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/19 19:38:06 by mirivera          #+#    #+#              #
#    Updated: 2019/05/14 14:08:37 by mirivera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADERS = ./fillit.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = main.c validate.c board.c

OBJ = main.o validate.o board.o

all: $(NAME) debug

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@$(CC) $(CFLAGS) -I $(HEADERS) -o main.o -c main.c
	@$(CC) $(CFLAGS) -I $(HEADERS) -o validate.o -c validate.c
	@$(CC) $(CFLAGS) -I $(HEADERS) -o board.o -c board.c
	@$(CC) $(CFLAGS) -I $(HEADERS) -o fillit $(OBJ) -L libft/ -lft -g

clean:
	@echo 'Removing object files'
	@rm -rf $(OBJ)

fclean: clean exe
	@echo 'Removing fillit executable'
	@rm -rf fillit

re: fclean exe all

test: re
	@python3 Fillit_Test_cases.py
	
exe:
	@rm -rf a.out*

debug:
	@$(CC) $(CFLAGS) -I $(HEADERS) main.c validate.c board.c libft/libft.a -g