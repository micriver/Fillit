/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:40:28 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/31 14:08:09 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** convert sharps to letters in string 2D array pieces
*/

void	pickup(char *board, int c)
{
	int i;

	i = -1;
	while (board[++i])
		board[i] = (board[i] == c) ? '.' : board[i];
}

int		place(char *board, char *piece, int i)
{
	int		x;
	int		j;
	char	letter;

	j = 0;
	x = 0;
	while (board[x] != '\n' && board[x])
		x++;
	letter = piece[j];
	while (piece[j])
	{
		if (!board[i] && x != 3)
			break ;
		(piece[j] == '\n' && x == 3) ? i-- : i;
		(piece[j] == '\n' && x != 4 && x != 3) ? i += (x - 4) : i;
		board[i] = (board[i] == '.' && piece[j] > 64) ? piece[j] : board[i];
		i++;
		j++;
	}
	return (placement_check(board, letter, x) ? 1 : 0);
}

int		solve(char *board, char **pieces, int i)
{
	if (!pieces[0])
		return (1);
	while (pieces[0] && pieces[0][0] < 64)
		pieces[0]++;
	while (board[++i])
	{
		if (place(board, *pieces, i) != 1 || (!solve(board, &pieces[1], -1)))
			pickup(&board[i], *pieces[0]);
		else
			return (1);
	}
	return (0);
}

void	builder(char *board, char **pieces, int size)
{
	int i;

	while (1)
	{
		i = -1;
		while (++i < (size * (size + 1)))
			board[i] = (i % (size + 1) == size) ? '\n' : '.';
		board[i] = '\0';
		if (!solve(board, pieces, -1))
		{
			size++;
			board = ft_strnew(size * (size + 5));
		}
		else
		{
			ft_putstr(board);
			exit(0);
		}
	}
}
