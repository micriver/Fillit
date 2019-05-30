/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:40:28 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/29 12:40:42 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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

void		pickup(char *board, char c)
{
	int i;

	i = 0;
	while (board[i])
	{
		if (board[i] == c)
		{
			board[i] = '.';
		}
		i++;
	}
}

int		backtrack(char *board, char **pieces, char letter)
{
	int		i;

	i = -1;
	// printf("This is what the board looks like right now:\n%s\n", board);
	// printf("Current piece to be placed:\n%s\n", pieces[0]);
	while (board[i] != '\n' && board[++i])
	{
		{
			if (!place(pieces[0], board, letter) || !solve(board, &pieces[1]))
				pickup(board, letter);
			else
				return (1);
		}
	}
	return (0);
}

int		solve(char *board, char **pieces)
{
	int		i;
	char	letter;

	i = -1;
	letter = '\0';
	if (!pieces[0]) //if we're at the NULL piece in the 2D array - the end...
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
