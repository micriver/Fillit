/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:40:28 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/27 12:49:46 by mirivera         ###   ########.fr       */
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

int		pickup(char *board, char c)
{
	int i;
	int charcount;

	i = 0;
	charcount = 0;
	// printf("%c\n", c);
	while (board[i])
	{
		if (board[i] == c)
		{
			board[i] = '.';
			charcount++;
		}
		i++;
	}
	//if we place a piece and after looking for THAT piece's character
	//and can't find more than that piece's
	return (charcount < 4) ? 0 : 1; 
}

int		backtrack(char *board, char **pieces, char letter)
{
	int		i;

	i = -1;
	
	printf("This is what the board looks like right now:\n%s\n", board);
	printf("Current piece to be placed:\n%s\n", pieces[0]);
	while (board[++i])
	{
		if (!place(pieces[0], board, letter))
			return (0);
		if (!solve(board, &pieces[1]))
		{
				printf("%d piece has been placed\n", i + 1);
				pickup(board, letter);
		}
		// printf("The empty board's current index is: %d\n", i);
		//if we place the current piece but its incorrect and there's still space on the board, increment the board index
		// if (!place(pieces[0], board, letter))
		// 	return (0);
		// {
		// 	pickup(board, letter);
		// 	i++;
		// 	place(pieces[0], board, letter);
		// }
		//here, its placing the piece AGAIN on top of the other piece then removing it and printing a blank board
		else
			printf("This is what the board looks like after placement:\n%s\n", board);
			return (1);
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

/* int		main(void)
{
	int g_size = 2;
	char *board;

	char **pieces = (char**)malloc(sizeof(char*) * 6);
	pieces[0] = "A...\nA...\nA...\nA...\n";
	pieces[1] = "...B.\n.BBB\n....\n....\n";
	pieces[2] = "C...\nC...\nCC..\n....\n";
	pieces[3] = "D...\nD...\nDD..\n....\n";
	pieces[4] = "..EE\n.EE.\n....\n....\n";
	// pieces[5] = "....\n....\n..FF\n..FF\n";
	pieces[5] = NULL;
	board = (builder(g_size));
	solve(board, pieces);
	
// 	ft_putstr(board);
// 	free(board);
// 	return (0);
	return (0);
} */
