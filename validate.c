/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 18:33:11 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/13 13:03:01 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
** checkchars goes through the string read from input,
** while limiting the chars, counts their occurences, and
** modulos that output according to amount of chars their should
** be in each tetrimino
**
** If there's a 21st character, then it needs to be a new line
** otherwise, we return FALSE
*/

int		checkchars(char *str, int d, int s, int nl)
{
	int i;

	i = 0;
	while (str[i] == '.' || str[i] == '#' || str[i] == '\n')
	{
		(str[i] == '.') ? d++ : d;
		(str[i] == '#') ? s++ : s;
		(str[i] == '\n') ? nl++ : nl;
		i++;
	}
	return (((d % 12) == 0) && ((s % 4) == 0) && ((nl + 1) % 5) == 0) ? 1 : 0;
}

int		checksides(char *str)
{
	int		i;
	int		sidecount;
	char	*piece;

	i = 0;
	sidecount = 0;
	piece = str;
	while (piece[i])
	{
		if (piece[i] == '#')
		{
			(piece[i + 1] == '#') ? sidecount++ : sidecount;
			(piece[i + 5] == '#') ? sidecount++ : sidecount;
			(piece[i - 1] == '#') ? sidecount++ : sidecount;
			(piece[i - 5] == '#') ? sidecount++ : sidecount;
		}
		if (piece[20])
			return (piece[20] != '\n') ? 0 : 1;
		i++;
	}
	return (sidecount == 6 || sidecount == 8) ? 1 : 0;
}
