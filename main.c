/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 10:30:12 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/03 19:48:00 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> //Don't forget to remove!!!!

/*
** If the number of parameters sent to your executable is not 1,
** your program must display its usage and exit properly ✓
*/

// This function is just getting the whole string
char *textarray(char *txt)
{
    int fd;
    char buf; // where we store the strings we've read into for further process
    char *dest; // the returned string we've read
    int x; // our incrememtor through the whole string

    x = 0;
    fd = open(txt, O_RDONLY); // opening the file arg,argv *file name we make*
    while (read(fd, &buf, 1)) // read into file and get the size of the whole string
        x++;
    if (x < 20) // if we get less than 20 chars then we know its not a valid piece
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

// function to seperate every 21 chars into a 2d array
char **ft_seperate(char *str) 
{
    char **dest; // creating our new 2d array
    int i;

    i = 0;
    dest = (char**)malloc(sizeof(char*) * 27); // allocating space for 2d array, limiting to 27 for a NULL string to finish the 2D array
    while (*str) // using our current string as a place holder which will change
    {
		//tetrimino check function should go here prior to populating the 2D array
        dest[i] = ft_strnew(21); // creating a new string of 21 bytes in each index

        ft_strncpy(dest[i], str, 21); // copy at every 21 pieces to new index
        str += 21; // adding 21 to old string to skip the 21 we already had
        i++;
    }
    dest[i] = NULL; // adding a null string at the end of the 2d array
    return (dest);
}

int		main(int ac, char **av)
{
    char *txt; // this will be our file.txt in argument count
    char **pieces; // our pieces from input file
	// char **ft_gridy; // place new pieces into grid after moved and validated
    int i;
	// int size = 22;

    i = 0;
    if (ac == 2) // a.out file.txt
    {
        txt = textarray(av[1]); // reads into file and stores whole string into txt
		if (!checkchars(txt, 0, 0, 0))
			ERROR;
		printf("%s", txt);
        pieces = ft_seperate(txt); // then seperate every 21 pieces into different index's
        /* printf("%s\n", pieces[1]); if you use this and not the while loop it will print just string in its corresponding index
        while (pieces[i]) // print all of the index's containg the 22 byte strings
        {
			if (!validate(pieces))
				ERROR;
            printf("%s", pieces[i]); // if you change this to a number it will print out the correspoding string at that address in our 2d array 4 times
            i++;
        } */
    }
	else
	{
		(void)av;
		USAGE;
	}
	return (0);
}



















/*
char	**ft_grid(int size)
{
	char **grid;
	int	row;
	int	col;

	row = 0;
	col = 0;
	grid = (char**)malloc(sizeof(char*) * (size + 1));
	while(row < size)
	{
		col = 0;
		grid[row] = (char*)malloc(sizeof(char*) * (size + 1));
		while (col < size)
		{
			grid[row][col] = '.';
			col++;
		}
		row++;
	}
	return(grid);
}

char	**move_pieces(char **grid, char **pieces, int size)
{
	char *row;
	char *col;
	int i;
	int j;
	char temp1;
	char temp2;
	
	j = 0;
	i = 0;
	temp1 = *ft_strnew(size);
	temp2 = *ft_strnew(size);
	row = ft_strnew(pieces[0][i]);
	col = ft_strnew(pieces[j][0]);
	if(!grid || !pieces)
		ERROR;
	while(grid[0][i])
	{
		i = 0;
		temp1 = *pieces[i];
		grid[0][i] = *ft_strcpy(&row[i], pieces[i]);
		row += 21;
		i++;
		//free(&temp1);
	}
	while(grid[j][0])
	{
		j = 0;
		temp2 = *pieces[j];
		grid[j][0] = *ft_strcpy(&col[j], pieces[j]);
		col += 21;
		j++;
		//free(&temp2);
	}
	return(grid);
}
*/
