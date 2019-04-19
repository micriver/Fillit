/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:10:02 by mirivera          #+#    #+#             */
/*   Updated: 2019/04/19 11:40:47 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define USAGE ft_putstr("usage: fillit target_file\n")
# define ERROR {ft_putstr("error\n"); \
    return (0); }
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"

/* typedef struct		tetrimino_node
{
	char			line[1];
	char 			line[2];
	char 			line[3];
	char 			line[4];
	struct tetrimino_node	*next;
}					tetrimino_node; */

void    fillit();
int		read_tetros(int fd);
int		validate_tetros(char *str);

#endif