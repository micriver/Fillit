/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:10:02 by mirivera          #+#    #+#             */
/*   Updated: 2019/06/03 10:04:38 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define USAGE ft_putstr("usage: fillit input_file\n")

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

int		placement_check(char *piece, char c, int x);
int		checkchars(char *str, int d, int s, int nl);
int		checksides(char *str, char letter);

/*
** Board management
*/

void	builder(char *board, char **pieces, int size);

/*
** Piece Solve & Drop
*/

int		solve(char *board, char **pieces, int i);
int		backtrack(char *board, char **pieces, char letter);
int		place(char *piece, char *board, int i);
void	pickup(char *board, int c);

#endif
