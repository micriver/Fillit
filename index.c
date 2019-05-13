/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:10:37 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/13 15:13:38 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     piece_index(char *str)
{
	static int i;
	static int sharp;

	i = 0;
	sharp = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			sharp++;
			return (i);
		}
		i++;
	}
	if (i == 20)
	{
		i = 0;
		sharp = 0;
	}
	return (0);
}
