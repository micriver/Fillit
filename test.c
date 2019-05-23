#include <stdlib.h>
#include <stdio.h>
#include "fillit.h"

int g_size = 3;

void    repos(char **board, int *i, int *j)
{
    int x;

    x = 0;
    while (x++ < g_size - 4)
    {
        if (!board[*i][*j])
        {
            *i += 1;
            *j = 0;
        }
        *j += 1;
    }
}

// char	**spot_return(char **board, int i, int j)
// {
// 	while (board[i][j] != '.' && board[i][j++]) // while the board's current coordinate is a letter, and while we iterate through the board's columns
//         if (!board[i][j]) //if we get to the end of the row's columns and they're full of letters, move to the next row
//         {
//             i++; //move to the next row 
//             j = 0; //start at the beginning of the next column
//         }
// 	return (board);
// }


/* int		value_placement(char **str, char *str2, int c)
{
	int k;
	int i;
	int j;
	
	while (str[i] && str2[k])
    {
        if (str2[k] >= 'A' && str2[k] <= 'Z')
        {
            if (str[i][j] != '.')
                return (0);
            str[i][j] = str2[k];
            c++;
            if (c == 4)
                return (1);

        }
        j++;
        if (str2[k] == '\n')
            repos(str, &i, &j);
        if (!str[i][j])
        {
            i++;
            j = 0;
        }
        k++;
    }
    return (0);
}
value_placement(board[i], piece[k], c);	 */



int		place(char *piece, char **board, int j, int c)
{
    int i;
    int k;

    i = 0;
    k = 0;
    while (piece[k] && piece[k] < 64) // iterate through the piece, and if the piece is not a letter
        k++;
    // lines below move the placement location over already placed letters
    // board = spot_return(board, i, j);
	while (board[i][j] != '.' && board[i][j++]) // while the board's current coordinate is a letter, and while we iterate through the board's columns
        if (!board[i][j]) //if we get to the end of the row's columns and they're full of letters, move to the next row
        {
            i++; //move to the next row 
            j = 0; //start at the beginning of the next column
        }
    while (board[i] && piece[k])
    {
        if (piece[k] >= 'A' && piece[k] <= 'Z')
        {
            if (board[i][j] != '.')
                return (0);
            board[i][j] = piece[k];
            c++;
            if (c == 4)
                return (1);

        }
        j++;
        if (piece[k] == '\n')
            repos(board, &i, &j);
        if (!board[i][j])
        {
            i++;
            j = 0;
        }
        k++;
    }
    return (0);
}

/* int		drop(char *piece, char **board, int j)
{
	int i = 0;
	int c = 0;
	int k = 0;

	while (piece[k] && piece[k] < 64)
		k++;
	while (board[i][j] != '.' && board[i][j]) {
		j++;
		if (!board[i][j]) {
			i++;
			j = 0;
		}
	}
	while (board[i] && piece[k]) {
		if (piece[k] >= 'A' && piece[k] <= 'Z' && board[i][j] != '.')
			return (0);
		if (piece[k] >= 'A' && piece[k] <= 'Z' && board[i][j] == '.') {
			board[i][j] = piece[k];
			c++;
		}
		if (c == 4)
			return (1);
		j++;
		if (piece[k] == '\n') {
			for (int x = 0; x < g_size - 4; x++) {
				if (!board[i][j]) {
					i++;
					j = 0;
				}
				j++;
			}
		}
		k++;
		if (!board[i][j]) {
			i++;
			j = 0;
		}
	}
	return (0);
} */

int main() {
	char **pieces = (char**)malloc(sizeof(char*) * 6);
	char **board = builder(g_size);
	pieces[0] = "A...\nA...\nA...\nA...\n";
	pieces[1] = "...B.\n.BBB\n....\n....\n";
	pieces[2] = "C...\nC...\nCC..\n....\n";
	pieces[3] = "D...\nD...\nDD..\n....\n";
	pieces[4] = "..EE\n.EE.\n....\n....\n";
	// pieces[5] = "....\n....\n..FF\n..FF\n";
	pieces[5] = NULL;
	while (!solve(board, pieces)) {
		g_size++;
		board = builder(g_size);
	}
	for (int i = 0; board[i]; i++)
		printf("%s", board[i]);
	return (0);
}
