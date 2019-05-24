/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:40:28 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/24 11:08:05 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** convert sharps to letters in string 2D array pieces
*/

void	convert_to_char(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			str[i] = c;
		i++;
	}
}

void	pickup(char **board, char c)
{
	int i;
	int j;

	i = 0;
	while (board[i])
	{
		j = 0;
		while (board[i][j])
		{
			if (board[i][j] == c)
				board[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		backtrack(char *board, char **pieces, char c)
{
	int		i;

	(void)pieces;
	(void)c;
	i = -1;
	while (board[i])
	{
		ft_putchar(board[i]);
		// if (!place(pieces[0], board, j, 0) || !solve(board, &pieces[1]))
			// pickup(board, c);
		// else
			// return (1);
		i++;
	}
	return (0);
}

int		solve(char *board, char **pieces)
{
	int		i;
	char	letter;

	i = -1;
	letter = '\0';
	if (!pieces[0])
		return (1);
	while (pieces[0][++i])
	{
		if (pieces[0][i] >= 64)
		{
			letter = pieces[0][i];
			break ;
		}
	}
	return (backtrack(board, pieces, letter)) ? 1 : 0;
}

int		main(void)
{
	int g_size = 2;
	char *board;
	
	board = (builder(g_size));
// 	ft_putstr(board);
// 	free(board);
// 	return (0);
	return (0);
}
