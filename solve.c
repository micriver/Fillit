/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:40:28 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/14 19:57:15 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		piece_length(char *str)
{
	int		i;
	int		length;
	char	*piece;

	i = 0;
	length = 0;
	piece = str;
	while (piece[i])
	{
		if (piece[i] == '#')
		{
			//square piece
			// (piece[i + 1] == '#' &&  piece[i + 5] == '#' && piece[i + 2] != '#') ? length = 2 : length;
			
			//line piece, vert + hori
			(piece[i + 3] == '#' || piece[i + 15] == '#') ? length = 4 : length;
			
			// (piece[i + 5] == '#') ? length++ : length;
			// (piece[i - 1] == '#') ? length++ : length;
			// (piece[i - 5] == '#') ? length++ : length;
		}
		i++;
	}
	return length;
}