/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 10:54:00 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/31 14:05:31 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_separate(char *str, char letter)
{
	char	**dest;
	char	*oldstr;

	oldstr = str;
	dest = (char**)malloc(sizeof(char*) * 27);
	while (*oldstr != '\0')
	{
		dest[g_size] = ft_strnew(21);
		ft_strncpy(dest[g_size], oldstr, 21);
		if (!checkchars(str, 0, 0, 0) || !checksides(dest[g_size], letter++))
			ERROR;
		g_size += 1;
		if (!oldstr[20])
			break ;
		oldstr += 21;
	}
	dest[g_size] = NULL;
	return (dest);
}

char	*textarray(char *txt)
{
	int		fd;
	char	buf;
	char	*dest;
	int		x;

	x = 0;
	fd = open(txt, O_RDONLY);
	while (read(fd, &buf, 1))
		x++;
	if (x < 20 || x > 545)
		ERROR;
	dest = ft_strnew(x);
	close(fd);
	x = 0;
	fd = open(txt, O_RDONLY);
	while (read(fd, &buf, 1))
		dest[x++] = buf;
	close(fd);
	return (dest);
}

int		main(int ac, char **av)
{
	char	*txt;
	char	**pieces;
	char	*board;
	int		size;

	size = 0;
	if (ac == 2)
	{
		txt = textarray(av[1]);
		pieces = ft_separate(txt, 'A');
		while (size * size < g_size * 4)
			size++;
		board = ft_strnew(size * (size + 1));
		builder(board, pieces, size);
		ft_putchar('\n');
	}
	else
		USAGE;
	return (0);
}
