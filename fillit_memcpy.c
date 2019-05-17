/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_memcpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 10:25:33 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/17 14:04:58 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/* void	*fillit_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;
	// size_t x;
	// char *character;

	// x = 0;
	// character = (char *)src;
	i = -1;
	while (++i < n){
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
	}
	// printf("%s\n", src);
	return (dest);
} */

int		place_piece(char **piece, char **board)
{
	int col = 0;
	int row = 0;
	int bd_col = 0;
	int bd_row = 0;
	char **tetrimino;
	int charcount = 0;
	
	tetrimino = piece;
	while (row < 4)
	{
		col = 0;
		bd_col = 0;
		while (col < 4)
		{
			if(charcount > 0)
				bd_col++;
			if (tetrimino[row][col] != '.')
			{
				// printf ("found a char %c\n", tetrimino[row][col]);
				board[bd_row][bd_col] = tetrimino[row][col];
				charcount++;
			}
			col++;
		}
		row++;
	}
	return (0);
}

#include <stdio.h>

int main()
{
	char **new_piece;
	char **board;
	char tet_piece[] = "....\n....\n.A..\nAAA.\n";
	new_piece = piece_parse(tet_piece, 0, 0);
	board = board_parse(4);

	printf("This is the piece as a 2D array:\n");
	print_board(new_piece, 4);
	printf("This is an empty board as a 2D array:\n");
	print_board(board, 4);

	//copy the piece to the board
	place_piece(new_piece, board);
	// fillit_memcpy(board, new_piece, sizeof(char*) * 4);

	printf("This is that empty board after the piece has been copied to it:\n");
	print_board(board, 4);
	return (0);
}