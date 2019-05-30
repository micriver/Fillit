/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_top_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 20:33:30 by brfeltz           #+#    #+#             */
/*   Updated: 2019/05/29 20:33:33 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*top_left(char *piece, int i)
{
	int x;
	int k;
	int j;

	j = 0;
	k = 0;
	x = 0;
	while (piece[i])
	{
		if (piece[i] == '.')
			i++;
	   	if (piece[i] >= 'A' && piece[i] <= 'Z')
		{
			j = i;
			break ;
		}
		i++;
	}
	i = 0;
	while (piece[x])
	{
		if (piece[x] >= 'A' && piece[x] <= 'Z')
			k += 1;
		if (k == 4)
			x += 1;
			break ;
		x++;
	}
	while(piece[i])
	{
		if(piece[i] >= 'A' && piece[i] <= 'Z')
			piece[i - j];
		i++;
	}
	return(piece);
}
/*
char	off_set(char *piece, int i)
{
	int x;

	x = 0;
	while(piece[x]

*/
int		main()
{
	char **pieces = (char**)malloc(sizeof(char*) * 6);

	pieces[0] = "...A\n...A\n...A\n...A\n";
	pieces[1] = NULL;
	//top_left(pieces[0], 0);
	for (int i = 0; pieces[i]; i++)
		printf("%c", *top_left(pieces[i], 0));
	return(0);
}
