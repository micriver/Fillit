/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:40:28 by mirivera          #+#    #+#             */
/*   Updated: 2019/06/03 13:29:59 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** pickup loops through the map looking for the given letter
** and changes them into dots to redo piece placement
*/

void	pickup(char *board, int c)
{
	int i;

	i = -1;
	while (board[++i])
		board[i] = (board[i] == c) ? '.' : board[i];
}

/*
** place uses some black magic to find the correct
** indexes to start copying from the piece string
** to the board string. place iterates using (x)
** before the next ('\n') char. The variable letter
** is initialized to the first index of the piece
** that was given from the solve function before.
** Then it iterates through the pieces indexes. If the board
** is at the end
*/

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

/*
** solve is where the backtracking occurs.
** It first looks to see if we've encountered
** the NULL array at the end of pieces for a cue to stop.
** Then it takes the incoming piece and iterates
** to the first letter, cutting the string down in the process.
** Then it iterates through the indexes on the board
** to begin backtracking. If place nor solve don't work
** the function tries placing the next piece instead,
** then the prior piece is picked up. If they both work,
** the board has been solved and (1) is returned to exit the function.
*/

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

/*
** builder uses the given size from the main
** replace the '\0' characters with either a
** '\n' char or a '.' according to the index and a
** modulo operation. Then the string is terminated.
** builder then calls the solve function where the
** hard work is all done. If solve returns (0)
** size is increased to increase the size of the board
** because there wasn't enough space for the last piece.
** Once solve is done, the board is printed
** and exit(0) is called.
*/

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
