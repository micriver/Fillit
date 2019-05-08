/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:52:57 by brfeltz           #+#    #+#             */
/*   Updated: 2019/05/07 22:09:12 by brfeltz          ###   ########.fr       */
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

int 	2d_size(char **str)
{
	int length;

	length = 0;
	while(str[length])
		length++;
	return(length);
}

void	**flood_fill(char **pieces)
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
	flood_fill(
