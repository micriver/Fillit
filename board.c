/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:52:57 by brfeltz           #+#    #+#             */
/*   Updated: 2019/05/31 13:49:52 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	builder(char *board, char **pieces, int size)
{
	int i;

	while (1)
	{
		i = -1;
		while (++i < (size * (size + 1))) //loop through according to the size, according to the number of pieces
			board[i] = (i % (size + 1) == size) ? '\n' : '.'; //fill the board with either new lines or dots
		board[i] = '\0'; //terminate the string
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