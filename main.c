/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 10:30:12 by mirivera          #+#    #+#             */
/*   Updated: 2019/04/18 20:04:17 by mirivera         ###   ########.fr       */
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
		while (i <= 5) 	//this loop is at 3 because
						//I only want to go through 
						//4 lines in a single tet rn
		{
			get_next_line(fd, &line);
			if (!validate_tetro(line))
				ERROR;
			printf("%s\n", line);
			i++;
		}
		// if (line == NULL)
		// 	printf("this is a new line\n");
	}
	else
	{
		(void)av;
		USAGE;
	}
	return (0);
}

/*
** This function loops through each LINE recieved from gnl
** looking for only the chars found in a valid tetrimino file
*/

int		validate_tetro(char *str)
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
