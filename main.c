/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 10:30:12 by mirivera          #+#    #+#             */
/*   Updated: 2019/04/30 15:39:23 by mirivera         ###   ########.fr       */
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
		int result;
		static char temp[546];
		char *buf;

		fd = open(av[1], O_RDONLY);
		while ((result = read(fd, temp, 546)) > 0)
		{
			// if you change to 546 you will read whole file
			buf = ft_strndup(temp, 21); 
		}
		printf("%s", buf);
	}
	else
	{
		(void)av;
		USAGE;
	}
	return (0);
}

int		validate_tetros(char *str)
{
	int i;
	
	i = 0;
	



	return (1);
}
