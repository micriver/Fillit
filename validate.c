/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 18:33:11 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/31 13:52:51 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** XXXXXXXXX


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
		if (i + 1 == 21)
			if (str[i] != '\n')
				return (0);
		i++;
	}
	return (((d % 12) == 0) && ((s % 4) == 0) && ((nl + 1) % 5) == 0) ? 1 : 0;
}

int		checksides(char *str, char letter)
{
	int		i;
	int		sidecount;

	i = -1;
	sidecount = 0;
	while (str[++i])
	{
		if (str[i] == '#' || str[i] == letter)
		{
			str[i] = letter;
			(str[i - 1] && (str[i - 1] == '#' || str[i - 1] == letter)) ? sidecount++ : sidecount;
			(str[i + 1] && (str[i + 1] == '#' || str[i + 1] == letter)) ? sidecount++ : sidecount;
			(str[i + 5] && (str[i + 5] == '#' || str[i + 5] == letter)) ? sidecount++ : sidecount;
			(str[i - 5] && (str[i - 5] == '#' || str[i - 5] == letter)) ? sidecount++ : sidecount;
		}
	}
	return (sidecount == 6 || sidecount == 8 ? 1 : 0);
}