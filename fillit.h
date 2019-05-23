/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michaelrivera <michaelrivera@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:10:02 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/23 14:02:57 by michaelrive      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define USAGE ft_putstr("usage: fillit input_file\n")
# define ERROR {ft_putstr("error\n"); exit(0);}
# define MVDWNROW {i++; j = 0;}

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"

/*
** Global
*/

int		g_size;

/*
** Validation
*/

int		checkchars(char *str, int d, int s, int nl);
int		checksides(char *str);
char	**piece_check(char **str);

/*
** Board management
*/

void	convert_to_char(char *str, char c);
char	**builder(int g_size);
void	pickup(char **board, char c);
void	print_board(char **board, int size);
void	free_board(char **grid, int size);

/*
** Solve
*/

int		nlmove(char *str, char **board);
int		place(char *piece, char **board, int j, int c);
void	pickup(char **board, char c);
int		solve(char **board, char **pieces);
int		backtrack(char **board, char **pieces, char c);

#endif
