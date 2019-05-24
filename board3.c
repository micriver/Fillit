/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:52:57 by brfeltz           #+#    #+#             */
/*   Updated: 2019/05/24 13:50:11 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*builder(int g_size)
{
	int		i;
	char	*board;

	i = 0;
	board = (char *)malloc(sizeof(char *) * (g_size * (g_size + 1)));
	while (i < (g_size * (g_size + 1)))
	{
		if ((i + 1) % (g_size + 1) == 0)
			board[i] = '\n';
		else
			board[i] = '.';
		i++;
	}
	board[i] = '\0';
	return (board);
}

// int		main(void)
// {
// 	int g_size = 2;
// 	char *board;

// 	board = (builder(g_size));
// 	ft_putstr(board);
// 	free(board);
// 	return (0);
// }