/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 10:30:12 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/14 14:09:37 by mirivera         ###   ########.fr       */
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

// function to seperate every 21 chars into a 2d array
char **ft_separate(char *str) 
{
    char **dest; // creating our new 2d array
	char *oldstr;
    int i;
	
    i = 0;
	oldstr = str;
    dest = (char**)malloc(sizeof(char*) * 27); // allocating space for 2d array, limiting to 27
    while (*oldstr)
    {
        dest[i] = ft_strnew(21); // creating a new string of 21 bytes in each index
        ft_strncpy(dest[i], oldstr, 21); // copy at every 21 pieces to new index
		i++;
        oldstr += 21; // adding 21 to old string to skip the 21 we alread had
		if (ft_strlen(oldstr) < 20) //this was for the garbage value tetriminos being printed
			break ;
    }
    dest[i] = NULL; //adding a null string at the end of the 2d array
    return (dest);
}

void    convert_to_char(char *str, char c)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '#')
        {
            str[i] = c;
        }
        i++;
    }
}

int		main(int ac, char **av)
{
    char *txt; // this will be our file.txt in argument count
    char letter; // this will be our file.txt in argument count
    char **pieces; // our pieces from input file
    char *board;
    int i;

    i = 0;
    letter = 'A';
    if (ac == 2) // a.out file.txt
    {
        txt = textarray(av[1]); // reads into file and stores whole string into txt
        if (!checkchars(txt, 0, 0, 0))
            ERROR;
        pieces = ft_separate(txt); // then seperate every 21 pieces into different index's
        board = ft_board(20);
        while (pieces[i]) // print all of the index's containing the 22 byte strings
        {
            if (!checksides(pieces[i])) // if you change this to a number it will print out the correspoding string at that address in our 2d array 4 times
				ERROR;
            convert_to_char(pieces[i], letter);
            letter++;
			// printf("%d.\n%s", i + 1, pieces[i]);
            board_placement(pieces[i], board);
			// printf("%d.\n%s", i + 1, board);
            i++;
        }
        printf("%s", board);
    }
	else
	{
		(void)av;
		USAGE;
	}
	return (0);
}
