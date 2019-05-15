/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:40:28 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/14 18:42:58 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		checksides(char *str)
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
			(piece[i + 1] == '#') ? length++ : length;
			(piece[i + 5] == '#') ? length++ : length;
			(piece[i - 1] == '#') ? length++ : length;
			(piece[i - 5] == '#') ? length++ : length;
		}
		if (piece[20])
			return (piece[20] != '\n') ? 0 : 1;
		i++;
	}
	return (length == 6 || length == 8) ? 1 : 0;
}