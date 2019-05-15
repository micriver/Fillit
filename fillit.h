/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:10:02 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/14 19:18:52 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define USAGE ft_putstr("usage: fillit input_file\n")
# define ERROR {ft_putstr("error\n"); exit(0);}

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"

int     piece_index(char *str);
int		checkchars(char *str, int d, int s, int nl);
int		checksides(char *str);
char	*ft_board(int size);
char    *board_placement(char *piece, char *board);
int     piece_length(char *str);

/*
** temp functions
*/

void	freegrid(char **grid, int size);
int     row_size(char **str);
int		col_size(char **str);
int		twod_size(char **str);
int		piece_size(char **piece);
char	place_piece(int size);
char	ft_fill(char **pieces, int i, int j);

#endif
