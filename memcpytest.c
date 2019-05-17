/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpytest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 09:19:11 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/17 10:06:56 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int main()
{
    // int col;
    // int row;
    char **new_piece;
    char **board;
    char tet_piece[] = "....\n....\n....\nAAAA\n";
    new_piece = piece_parse(tet_piece, 0, 0);
    board = board_parse(4);

    // char *data[] = {"jan", "fev", "mar", "apr", "mai", "jun", "jul", "aug"};
    // char *data2[SIZE];

    printf("This is the piece as a 2D array:\n");
    print_board(new_piece, 4);
    printf("This is an empty board as a 2D array:\n");
    print_board(board, 4);

    //copy the piece to the board
    ft_memcpy(board, new_piece, sizeof(char*) * 4);

    printf("This is that empty board after the piece has been copied to it:\n");
    print_board(board, 4);
    return (0);
}