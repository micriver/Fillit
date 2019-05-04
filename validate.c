/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 18:33:11 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/03 20:03:06 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (str[i] == 21)
			if (str[i] != '\n')
				return (0);
		i++;
	}
	return (((d % 12) == 0) && ((s % 4) == 0) && (((nl + 1) % 5) == 0) && 
		((i + 1) % 21) == 0) ? 1 : 0;
}