/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:40:28 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/17 08:50:46 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	copy_piece(char *piece, char **board)
{
	int row;
	int column;
	int piece;
	int count;

	row = 0;
	column = 0;
	piece = 0;
	count = 0;
	while (board[row][column] && board[row][column] != '.') 
	{
		if (board[row][column] == '\n') 
		{
			row++;
			column = -1;
		}
		column++;
	}
	while ((piece[piece] == '.' || piece[piece] == '\n') && piece[piece])
		piece++;
	while(board[row][column]) 
	{
		if (board[row][column] == '.' && piece[piece] >= 'A' && piece[piece] <= 'Z') 
		{
			board[row][column] = piece[piece];
			count++;
		}
		if (board[row][column] == '\n') 
		{
			row++;
			column = -1;
		}
		column++;
		piece++;
		if (count == 4)
			break;
	}
}

