/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:10:02 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/16 18:06:33 by mirivera         ###   ########.fr       */
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

/*
** Validation
*/

int		checkchars(char *str, int d, int s, int nl);
int		checksides(char *str);
char	**piece_check(char **str);

/*
** Board management
*/

void    convert_to_char(char *str, char c);
char	**piece_parse(char *str, int row, int col);
char	**board_parse(int size);
char    *board_placement(char *piece, char *board);
void	print_board(char **board, int size);
void	free_board(char **grid, int size);

#endif
