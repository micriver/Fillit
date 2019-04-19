/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 10:30:12 by mirivera          #+#    #+#             */
/*   Updated: 2019/04/19 11:44:38 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> //Don't forget to remove!!!!

/*
** If the number of parameters sent to your executable is not 1,
** your program must display its usage and exit properly ✓
*/

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		int fd;
		//char *line;
		int i;

		i = 0;
		fd = open(av[1], O_RDONLY);
		if (!read_tetros(fd))
			ERROR;
	}
	else
	{
		(void)av;
		USAGE;
	}
	return (0);
}

/*
** The read function validates the given input and places the 
** valid tetriminos in memory to be called later
**
** If there are errors, we return (0), otherwise return TRUE
*/

int		read_tetros(int fd)
{
	//may not be necessary	
	//static char 	*temp[4864];

	//for the buff_size below, do we count the number of chars 
	//in a 26 tetro file and set that 
	//as the max buff_size?
	char			buffer[BUFF_SIZE + 1];
	//char			*tempmem;
	int				readresult;

	readresult = 0;
	//quick checks
	if (fd < 0 || fd >= 4864)
		return (0);
	//start populating the buffer string with all tetro chars from file
	if (read(fd, buffer, BUFF_SIZE) < 0)
		return (0);
	
	//terminate the string
	buffer[readresult] = '\0';
	printf("%s\n", buffer);

	//feed the whole string recieved from the read function above to validate the tetros!!!!	
	if (!validate_tetros(buffer))
				return (0);

	//figure out a way to place the validated buffer string into a linked list 
	//separated by their new lines into their own nodes
	//----list creation and placement function-----
	return (1);
}

int		validate_tetros(char *str)
{
	int i;
	
	i = 0;
	//charcountcheck can be in another function
	if (str[1] == '\n')
	{
		printf("It IS seeing the newline char\n");
	}
	/* if (ft_strlen(str) != 4)
	{
		// else
		printf("It's NOT seeing the newline char");
		// return (0);
	} */
	//This loop checks for invalid chars
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#')
			return (0);
		i++;
	}
	return (1);
}
