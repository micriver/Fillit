/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:40:28 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/24 12:51:41 by mirivera         ###   ########.fr       */
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

void	pickup(char *board, char c)
{
	int i;

	i = 0;
	while (board[i])
	{
		if (board[i] == c)
			board[i] = '.';
		i++;
	}
}

int		backtrack(char *board, char **pieces, char letter)
{
	int		i;

	i = -1;
	// ft_putstr(board);
	// ft_putchar('\n');
	// ft_putstr(pieces[0]);
	// ft_putchar('\n');
	while (board[i])
	{
		if (!place(pieces[0], board) || !solve(board, &pieces[1]))
			pickup(board, letter);
		else
			return (1);
		i++;
	}
	return (1);
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
}
