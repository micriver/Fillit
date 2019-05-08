/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:52:57 by brfeltz           #+#    #+#             */
/*   Updated: 2019/05/08 16:20:50 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_grid(int size)
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

void	freegrid(char **grid, int size)
{
	int i;

	i = 0;
	while(i < size)
	{
		free(grid[i]);
		i++;
	}
}

int		row_size(char **str)
{
	int row;

	row = 0;
	while(str[row][0])
		row++;
	return(row);
}

int		col_size(char **str)
{
	int col;

	col = 0;
	while(str[0][col])
		col++;
	return(col);
}

int 	twod_size(char **str)
{
	int length;

	length = 0;
	while(str[length])
		length++;
	return(length);
}

int		piece_size(char **piece)
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
char	place_piece(int size)
{
	int i;
	char piece;

	piece = '#';
	i = 0;
	while(i < size)
	{
		ft_putchar(piece);
		i++;
	}
	return(piece);
}
char	ft_fill(char **pieces, int i, int j)
{
	char **new_grid;
	char piece;

	i = row_size(pieces);
	j = col_size(pieces);
	piece = place_piece(piece_size(pieces));
	new_grid = ft_grid(twod_size(pieces));
	while(new_grid[i][j])
	{
		ft_fill(new_grid, i + 1, j);
		ft_fill(new_grid, i - 1, j);
		ft_fill(new_grid, i, j + 1);
		ft_fill(new_grid, i, j - 1);
		piece = new_grid[i][j];
		i++;
		j++;
	}
	return(piece);
}

/*char	**new_2d(char **pieces)
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
