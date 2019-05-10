/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:52:57 by brfeltz           #+#    #+#             */
/*   Updated: 2019/05/09 21:45:51 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	**ft_grid(int size) // grid to place pieces on #
{
	char **grid;
	int	row;
	int	col;

	row = 0;
	col = 0;
	grid = (char**)malloc(sizeof(char*) * (size + 1));
	while(row < size)
	{
		col = 0;
		grid[row] = (char*)malloc(sizeof(char*) * (size + 1));
		while (col < size)
		{
			grid[row][col] = '.';
			col++;
		}
		row++;
	}
	return(grid);
}

void	print_grid(char **grid)
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while(x < 4)
		{
			ft_putchar(grid[x][y]);
			x++;
			if (x % 4 != 0)
				ft_putchar('.');
		}
		y++;
		ft_putchar('\n');
	}
}

int		main()
{
	int i = 26;
	print_grid(ft_grid(i));
	return(0);
}

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
