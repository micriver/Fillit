/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:05:13 by brfeltz           #+#    #+#             */
/*   Updated: 2019/05/16 15:16:30 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_board(int size)
{
	char **board;
	int row;
	int col;

	row = 0;
	col = 0;
	board = (char**)malloc(sizeof(char*) * (size + 1));
	while (row < size)
	{
		col = 0;
		board[row] = (char*)malloc(sizeof(char) * (size + 1)); // or ft_strnew if we leak
		while (col < size)
		{
			board[row][col] = '.';
			col++;
		}
		row++;
	}
	board[row] = NULL;
	return(board);
}

void	free_board(char **grid, int size) // free memory for our board when we're finished with it
{
	int i;

	i = 0;
	while(i < size)
	{
		free(grid[i]);
		i++;
	}
}
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

int		main()
{
	char **board;
	char size;

	size = 5;
	board = ft_board(size);
	print_board(board, size);
	
	return(0);
}
