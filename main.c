/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michaelrivera <michaelrivera@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 10:54:00 by mirivera          #+#    #+#             */
/*   Updated: 2019/06/02 19:43:21 by michaelrive      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** The string that was created after reading 
** the file is cut into it's own string and 
** placed into a 2D array via ft_strncpy. 
** Checkchars and checksides is called here 
** since this is the first time
** we separate the long string into each piece. 
** These functions will return an error message
** if either one of them returns a zero (0). 
** Our g_size variable counts the number
** of pieces placed into the array and then uses that
** to determine the size of the board. 
*/

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
		{
			ft_putstr("error\n");
			exit(0);
		}
		g_size += 1;
		if (!oldstr[20])
			break ;
		oldstr += 21;
	}
	dest[g_size] = NULL;
	return (dest);
}

/*
** We open, read the file and then place read's return value 
** inside (x). (x) is then check to make sure we have a valid amount
** of tetriminos. If the number of chars is under 20 characters,
** then we know there isn't at least 1 full single tetrimino. 
** If (x) is over 545, then there are more than 26 tetriminos. 
** After that check, we create the string we're returning, (dest),
** and set (x) as it's size in ft_strnew. The buffer is then fed
** via a while loop into the (dest) string.
** The file is then closed a last time.
*/

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
	{
		ft_putstr("error\n");
		exit(0);
	}
	dest = ft_strnew(x);
	close(fd);
	x = 0;
	fd = open(txt, O_RDONLY);
	while (read(fd, &buf, 1))
		dest[x++] = buf;
	close(fd);
	return (dest);
}

/*
** If the number of arguments isn't 1,
** then we display the usage message, defined by USAGE.
** If there's at least one argument, we call textarray
** to create a string of the file. Then we take that string
** and send it to be separated into pieces in a 2D array
** by ft_separate. The size while loop determines
** the smallest possible size for the board to be created
** using the g_size value given during ft_separate.
** That size is used to create the empty board string. 
** We then call builder to create the board in memory
** and solve the problem. Ft_putchar creates the required 
** new line char after the hard work's been done
*/

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
