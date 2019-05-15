/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:40:28 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/15 12:41:50 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		piece_length(char *str)
{
	int		i;
	int		length;
	char	*piece;
	// char	c;

	i = 0;
	length = 0;
	piece = str;
	// c = piece[i] >= 'A' || piece[i] <= 'Z';
	while (piece[i])
	{
		if (piece[i] >= 'A' || piece[i] <= 'Z')
		{
			//square piece
			((piece[i + 1] >= 'A' || piece[i + 1] <= 'Z') &&  (piece[i + 5] >= 'A' || piece[i + 5] <= 'Z') && (piece[i + 2] != 'A' || piece[i + 2] != 'Z')) ? length = 2 : length;
			
			//line piece, vert + hori
			// (piece[i + 3] >= 'A' || piece[i + 3] <= 'Z' || piece[i + 15] >= 'A' || piece[i + 15] <= 'Z') ? length = 4 : length;
			
			// (piece[i + 5] == '#') ? length++ : length;
			// (piece[i - 1] == '#') ? length++ : length;
			// (piece[i - 5] == '#') ? length++ : length;
		}
		i++;
	}
	return length;
}