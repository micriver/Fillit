/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:52:57 by brfeltz           #+#    #+#             */
/*   Updated: 2019/05/14 19:57:16 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
** creates a board in memory
*/

char	*ft_board(int size)
{
	char *board;
	int i;
	int x;

	i = 0;
	x = 0;
	board = (char*)malloc(sizeof(char) * size + 1);
	while (i < size)
	{
		if ((i + 1) % 5 == 0)
			board[i] = '\n';
		else
			board[i] = '.';
		i++;
	}
	board[i + 1] = '\0';
	return (board);
}

/*
** copies the strings from pieces onto the board in memory
*/

char	*board_placement(char *piece, char *board)
{
	int i;
	int x;
	int charcount;
	
	i = 0;
	x = 0;
	charcount = 0;
	while (piece[i] != '\0')
	{
		if (piece[i] != '.' && piece[i] != '\n')
		{
			x = i;
			break ;
		}
		i++;
	}
	while (piece[i] != '\0' && charcount != 4)
	{
		if (piece[i] != '.' && piece[i] != '\n')
		{
			board[i - x] = piece[i];
			charcount++;
		}
		i++;
	}
	return (board);
}

/* int		main()
{
	// int i = 26;
	printf("%s\n", ft_board(19));
	return(0);
}
 */



































/*
void	freegrid(char **grid, int size) // free memory for our board when we're finished with it
{
	int i;

	i = 0;
	while(i < size)
	{
		free(grid[i]);
		i++;
	}
}

int		row_size(char **str) // the size of the row in the 2d array str[x][0]
{
	int row;

	row = 0;
	while(str[row][0])
		row++;
	return(row);
}

int		col_size(char **str) // the size of the colum in the 2d array str[0][y]
{
	int col;

	col = 0;
	while(str[0][col])
		col++;
	return(col);
}

int 	twod_size(char **str) // the size of our 2d array
{
	int length;

	length = 0;
	while(str[length])
		length++;
	return(length);
}

int		piece_size(char **piece) // get the size of each piece, should be 4
{
	int i;
	int size;
	char sharp;

	i = 0;
	while(piece[i])
	{
		if(piece[i][0] == '#' )
			size = size + 1;
		else if(piece[0][i] == '#')
			size = size + 1;
		i++;
	}
	return(size);
}
char	place_piece(int size) // print out piece
{
	int i;
	int row;
	char piece;

	piece = '#';
	i = 0;
	while(i < size)
		piece[i++];
	return(piece);
}
char	ft_fill(char **pieces, int i, int j) // fill a new 2d array with pieces and print them out
{
	char **new_grid;
	char piece;

	i = row_size(pieces);
	j = col_size(pieces);
	piece = place_piece(piece_size(pieces));
	new_grid = ft_grid(twod_size(pieces));
	while(new_grid[i][j])
	{

	}
	printf("%c\n", piece);
	return(piece);
}
/
char	**new_2d(char **pieces)
{
	char **new_grid;
	int row;
	int col;

	new_grid = ft_grid(2d_size(pieces));
	row = row_size(pieces);
	col = col_size(pieces);

	if (row < 0 || col < 0)
		return(ERROR);
	if (!pieces[row][col])
		return(ERROR);
*/
