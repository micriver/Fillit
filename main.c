/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 10:30:12 by mirivera          #+#    #+#             */
/*   Updated: 2019/04/18 14:44:36 by mirivera         ###   ########.fr       */
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
		char *line;
		int i;

		i = 0;
		fd = open(av[1], O_RDONLY);
		while (i <= 3)
		{
			get_next_line(fd, &line);
			// if ((get_next_line(fd, &line) == 0))
			// 	return (0);
			if (validate_tetro(line) == 0)
				ERROR;
			i++;
		}
		if (line == NULL)
				printf("this is a new line\n");
		printf("%s\n", line);
		// if (i % 4 != 0)
		// {
		// 	ft_putstr(ERROR);
		// 	return (0);
		// }
	}
	else
	{
		(void)av;
		USAGE;
	}
	return (0);
}

/*
** This function loops through each line recieved from gnl
** looking for only the chars found in a valid tetrimino file
*/

int		validate_tetro(char *str)
{
	int i;
	int dotcount;
	int sharpcount;
	
	i = 0;
	dotcount = 0;
	sharpcount = 0;
	//charcountcheck can be in another function
	if (ft_strlen(str) != 4)
		return (0);
	//This loop checks for invalid chars
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#')
			return (0);
		//This loop counts the number of sharps but since validate tetro
		//looks onyl at one line at a time, we can't count the number of sharps
		//across the whole tetrimino just yet
		// if (str[i] == '#')
		// {
		// 	sharpcount++;
		// 	if (sharpcount > 4)
		// 		return (0);
		// }	
		i++;
	}
	// i = 0;
	// while (str[i])
	// {

	// 	i++;
	// }
	
	//printf("%d dots, %d sharps\n", dotcount, sharpcount);
	return (1);
}
