/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 10:54:00 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/31 11:17:59 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	convert_to_char(char **str, char c)
{
	int i;

	i = 0;
	while (str[0][i] != '\0')
	{
		if (str[0][i] == '#')
			str[0][i] = c;
		i++;
	}
}

/* char		**piece_check(char **str)
{
	char **pieces;
	char letter;
	int i;

	i = 0;
	letter = 'A';
	pieces = str;
	while (pieces[i])
	{
		if (!checksides(pieces))
			ERROR;
		convert_to_char(pieces, letter);
		// letter++;
		i++;
	}
	return (str);
} */

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

int		checksides(char *str, char letter)
{
	int		i;
	int		sidecount;

	i = -1;
	sidecount = 0;
	while (str[++i])
	{
		if (str[i] == '#' || str[i] == letter)
		{
			str[i] = letter;
			(str[i - 1] && (str[i - 1] == '#' || str[i - 1] == letter)) ? sidecount++ : sidecount;
			(str[i + 1] && (str[i + 1] == '#' || str[i + 1] == letter)) ? sidecount++ : sidecount;
			(str[i + 5] && (str[i + 5] == '#' || str[i + 5] == letter)) ? sidecount++ : sidecount;
			(str[i - 5] && (str[i - 5] == '#' || str[i - 5] == letter)) ? sidecount++ : sidecount;
		}
	}
	return (sidecount == 6 || sidecount == 8 ? 1 : 0);
}

int		place(char *board, char *piece, int i)
{
	int x;
	int j;
	char letter;

	j = 0;
	x = 0;
	while (board[x] != '\n' && board[x])
		x++;
	letter = piece[j];
	while (piece[j])
	{
		if (!board[i] && x != 3) //<---test!!!!
			break ;
		(piece[j] == '\n' && x == 3) ? i-- : i; //<---test!!!!
		(piece[j] == '\n' && x != 4 && x != 3) ? i += (x - 4) : i; //<---test!!!!
		board[i] = (board[i] == '.' && piece[j] > 64) ? piece[j] : board[i]; //copying is done here
		i++;
		j++;
	}
	return (placement_check(board, letter, x) ? 1 : 0);
}
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
			(piece[i - x - 1] && (piece[i - x - 1] == c)) ? sidecount++ : sidecount;
			(piece[i + x + 1] && (piece[i + x + 1] == c)) ? sidecount++ : sidecount;
		}
	}
	return (sidecount == 6 || sidecount == 8 ? 1 : 0); // ~~~~~
}

void        pickup(char *board, int c)
{
	int i;

	i = -1;
	while (board[++i])
		board[i] = (board[i] == c) ? '.' : board[i];
}

int        solve(char *board, char **pieces, int i)
{
	// static int x = 0;
	// char	letter;

	// letter = '\0';
	// printf("This is the piece we're about to solve:\n%s\n", pieces[0]);
	if (!pieces[0]) //if we're at the NULL piece in the 2D array - the end...
		return (1);
	while (pieces[0] && pieces[0][0] < 64)
		pieces[0]++;
	while(board[++i])
	{
		if (place(board, *pieces, i) != 1 || (!solve(board, &pieces[1], -1)))
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
		if (!solve(board, pieces, -1))
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

char	**ft_separate(char *str, char letter) 
{
	char **dest; // creating our new 2d array
	char *oldstr;
	
	oldstr = str;
	dest = (char**)malloc(sizeof(char*) * 27); // allocating space for 2d array, limiting to 27
	while (*oldstr != '\0')
	{
		dest[g_size] = ft_strnew(21); // creating a new string of 21 bytes in each index
		ft_strncpy(dest[g_size], oldstr, 21); // copy at every 21 pieces to new index
		if (!checkchars(str, 0, 0, 0) || !checksides(dest[g_size], letter++))
			ERROR;
		g_size += 1;
		if (!oldstr[20]) //this was for the garbage value tetriminos being printed
			break ;
		oldstr += 21; // adding 21 to old string to skip the 21 we alread had
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
	// int i = 0;
	
	size = 0;
	if (ac == 2)
	{
		txt = textarray(av[1]);
		// if (!checkchars(txt, 0, 0, 0))
		// 	ERROR;
		pieces = ft_separate(txt, 'A');
		// while(i <= g_size)
		// {
		// 	printf("%d.\n%s\n", i + 1, pieces[i]);
		// 	i++;
		// }
		// piece_check(pieces);
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
