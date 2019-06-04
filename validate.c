/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 18:33:11 by mirivera          #+#    #+#             */
/*   Updated: 2019/06/03 20:03:14 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** checkchars loops through each string
** given by ft_separate. The while loop looks at
** dots, sharps, and nl chars. If it sees a dot,
** increase the dot count and so on so forth
** the rest of the characters. If there is a 21st
** index in the given string, it MUST be a new line
** char or else the input file is not valid.
** Using a ternary statement to save space, we return
** (1) or (0) based on the remainders from each variable's
** result. There will always be 12 dots and 4 sharps
** in a valid tetrimino piece.
** It adds (+ 1) to nl because the last tetrimino
** will only have 4 nl chars so we need to force
** the total to be divisable by 5 to account
** for the nl chars found between more than one tetriminos.
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

/*
** checksides loops through the given string
** and converts each sharp it encounters
** in the while loop to a letter.
** A series of ternary operators search for sharps OR letters
** (depending on the sharp that we're on in the loop).
** When it finds a sharp, it uses pointer arithmetic to look
** before, in front of, underneath (bottom side) and above (top side)
** the operator for other sharps. It only enters the statement if
** there is an index before, after, above or below with the first checks.
** If there are sharps on any side, the sidecount variable
** increases by one. Square shapes have a total of 8 sides touching
** while all other pieces have 6. A ternary operator is used
** to return either (1) or (0) depending on whether or not
** the current piece's shape is a valid tertimino shape
*/

int		checksides(char *str, char letter)
{
	int		i;
	int		sidecount;

	i = -1;
	sidecount = 0;
	while (str[++i])
	{
		if (str[i] == '#')
		{
			str[i] = letter;
			(str[i - 1] && (str[i - 1] == '#' ||
				str[i - 1] == letter)) ? sidecount++ : sidecount;
			(str[i + 1] && (str[i + 1] == '#' ||
				str[i + 1] == letter)) ? sidecount++ : sidecount;
			(str[i + 5] && (str[i + 5] == '#' ||
				str[i + 5] == letter)) ? sidecount++ : sidecount;
			(str[i - 5] && (str[i - 5] == '#' ||
				str[i - 5] == letter)) ? sidecount++ : sidecount;
		}
	}
	return (sidecount == 6 || sidecount == 8 ? 1 : 0);
}

/*
** Placement check is very similar to checksides except
** that it looks at pieces that have already been placed.
** The board could be much larger than its original size
** so the given variable (x) is passed in to be used in pointer arithmetic.
** (x) is the total number of indexes in the board rows
** before the new line char. It subtracts/adds (x)
** (as well as -1 for the new line char)
** so that it can look at the next row below/above
** to check for the same letter of the current piece being placed. If it finds
** another letter, then it does not increase the side count. If the sidecount
** us not 6 or 8, then the current piece being placed must be picked up
** and the next tried instead.
*/

int		placement_check(char *piece, char c, int x)
{
	int		i;
	int		sidecount;

	i = -1;
	sidecount = 0;
	while (piece[++i])
	{
		if (piece[i] == c)
		{
			(piece[i - 1] && (piece[i - 1] == c)) ? sidecount++ : sidecount;
			(piece[i + 1] && (piece[i + 1] == c)) ? sidecount++ : sidecount;
			(piece[i - x - 1] && (piece[i - x - 1] == c))
				? sidecount++ : sidecount;
			(piece[i + x + 1] && (piece[i + x + 1] == c))
				? sidecount++ : sidecount;
		}
	}
	return (sidecount == 6 || sidecount == 8 ? 1 : 0);
}
