/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 10:30:12 by mirivera          #+#    #+#             */
/*   Updated: 2019/04/17 20:02:28 by mirivera         ###   ########.fr       */
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
		while (i <= 4)
		{
			get_next_line(fd, &line);
			printf("%s\n", line);
			validate_tetro(line);
			i++;
		}
		
		// if (ft_strchr(line, '\n'))
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
	int nlcount;
	
	i = 0;
	dotcount = 0;
	sharpcount = 0;
	nlcount = 0;
	//charcountcheck can be in another function
	if (ft_strlen(str) != 4)
		ERROR;
	while (str[i] == '.' || str[i] == '#' || str[i] == '\n')
	{
		if (str[i] == '.')
			dotcount++;
		if (str[i] == '#')
			sharpcount++;
		if (str[i] == '\n')
			nlcount++;
		i++;
	}
	printf("%d\n", dotcount);
	printf("%d\n", sharpcount);
	printf("%d\n", nlcount);
	return (0);
}
