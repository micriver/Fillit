/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:52:57 by brfeltz           #+#    #+#             */
/*   Updated: 2019/05/16 16:34:57 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** convert sharps to letters in string 2D array pieces
*/

void    convert_to_char(char *str, char c)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '#')
        {
            str[i] = c;
        }
        i++;
    }
}

/*
** take a piece string and converts to a 2D piece array
** row and col will be fed value of 0 for top left corner
*/

char	**piece_parse(char *str, int row, int col)
{
	char **new_piece;
	char *old_piece;
	int i;

	i = 0;
	old_piece = str;
	new_piece = malloc(sizeof(char *) * 4);
	while (row < 4)
	{
		col = 0;
		new_piece[row] = malloc(sizeof(char) * 4);
		while (col < 4)
		{
			if (old_piece[i] == '\n')
				i++;
			else if (old_piece[i] == '\0')
				break ;
			new_piece[row][col] = old_piece[i];
			col++;
			i++;
		}
		row++;
	}
	return (new_piece);
}

/*
** create 2d board in memory
*/

char	**board_parse(int size)
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

/*
** print 2d board from memory
*/

//This might have to be slightly modified 
//to print out the final smallest square
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
	while(i < size)
	{
		free(grid[i]);
		i++;
	}
}

int		main(void)
{
	char **new_piece;
	char tet_piece[] = "....\n....\n....\n####\n";

	new_piece = piece_parse(tet_piece, 0, 0);
	print_board(new_piece, 4);
	return(0);
}
