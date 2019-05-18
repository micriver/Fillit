/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:52:57 by brfeltz           #+#    #+#             */
/*   Updated: 2019/05/17 22:30:14 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**builder(int g_size)
{
	int		i;
	int		j;
	char	**board;

	i = 0;
	g_size += 1;
	board = (char **)malloc(sizeof(char *) * g_size);
	while (i < (g_size - 1))
	{
		board[i] = (char*)malloc(sizeof(char) * g_size + 1);
		j = 0;
		while (j < (g_size - 1))
		{
			board[i][j] = '.';
			j++;
		}
		board[i][g_size - 1] = '\n';
		board[i][g_size] = '\0';
		i++;
	}
	board[g_size - 1] = NULL;
	return (board);
}

/*
** print 2d board from memory
*/

void	print_board(char **board, int size)
{
	int row;
	int col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			ft_putchar(board[row][col]);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

/*
** free memory for our board when we're finished with it
*/

void	free_board(char **grid, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(grid[i]);
		i++;
	}
}
