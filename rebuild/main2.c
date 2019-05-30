/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 10:54:00 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/30 14:33:48 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void        pickup(char *board, int c)
{
	int i;

	i = -1;
	while (board[i++])
	{
		if (board[i] == c)
		{
			board[i] = '.';
		}
	} 
}

int        solve(char *board, char **pieces)
{
	int		i;
	char	letter;

	i = -1;
	letter = '\0';
	if (!pieces[0]) //if we're at the NULL piece in the 2D array - the end...
		return (1);
	while (pieces[0] && pieces[0][0] < 64)
		pieces[0]++;
	while(board[i++])
	{
		if ((!place(board, *pieces, i)) || (!solve(board, &pieces[1])))
			pickup(&board[i], *pieces[0]);
		else
			return (1);
	}
	return (0);
}
void	builder(char *board, char **pieces, int size)
{
	int i;
	
	while (1)
	{
		i = -1;
		while (++i < (size * (size + 1))) //loop through according to the size, according to the number of pieces
			board[i] = (i % (size + 1) == size) ? '\n' : '.'; //fill the board with either new lines or dots
		board[i] = '\0'; //terminate the string
		if (!solve(board, pieces))
		{
			size++;
			board = ft_strnew(size * (size + 5));
		}
		else
		{
			ft_putstr(board);
			exit(0);
		}
	}
}

char	**ft_separate(char *str) 
{
	char **dest; // creating our new 2d array
	char *oldstr;
	int i;
	
	i = 0;
	oldstr = str;
	dest = (char**)malloc(sizeof(char*) * 27); // allocating space for 2d array, limiting to 27
	while (*oldstr)
	{
		dest[g_size] = ft_strnew(21); // creating a new string of 21 bytes in each index
		ft_strncpy(dest[i], oldstr, 21); // copy at every 21 pieces to new index
		g_size++;
		oldstr += 21; // adding 21 to old string to skip the 21 we alread had
		if (ft_strlen(oldstr) < 20) //this was for the garbage value tetriminos being printed
			break ;
	}
	dest[g_size] = NULL; //adding a null string at the end of the 2d array
	return (dest);
}

char	*textarray(char *txt)
{
	int fd;
	char buf; // where we store the strings we've read into for further process
	char *dest; // the returned string we've read
	int x; // our incrememtor through the whole string

	x = 0;
	fd = open(txt, O_RDONLY); // opening the file arg,argv *file name we make*
	while (read(fd, &buf, 1)) // read into file and get the size of the whole string
		x++;
	if (x < 20 || x > 545) // if we get less than 20 chars then we know its not a valid piece, if we get more than 545, then we know there's more than 26 tetriminos
		ERROR;
	dest = ft_strnew(x); // allocate space for our new strin | at the size of x(strlen)
	close(fd); // close fd as we are not using for this portion anymore
	x = 0; // set x to 0 again to place the string into dest 1 by 1
	fd = open(txt, O_RDONLY);
	while (read(fd, &buf, 1))
		dest[x++] = buf; /// while reading agian place every piece intp buff
	close(fd); // final close
	return (dest); // return whole string in file.txt
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
		if (!checkchars(txt, 0, 0, 0))
			ERROR;
		pieces = ft_separate(txt);
		piece_check(pieces);
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
