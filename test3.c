#include <stdlib.h>
#include <stdio.h>
#include "fillit.h"

int g_size = 2; //start out @ 2 for the smallest possible square piece board

void    repos(char **board, int *i, int *j) //dereferences the values in the stack and doesn't return anything
{
	int x;

	x = 0;
	while (x++ < g_size - 4)
	{
		if (!board[*i][*j]) //when we get to a terminating char for our board
		{
			*i += 1; //move down a row
			*j = 0; //place the focus at the current column
		}
		*j += 1; //move into the next column
	}
}

int		place(char *piece, char **board, int j, int c)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (piece[k] && piece[k] < 64) // iterate through the piece, and if the piece is not a letter
		k++;
	// letter_skip(board, &i, &j);
	// lines below move the placement location over already placed letters
	// WHILE LOOP SHOULD BE MADE INTO FUNCTION
	while (board[i][j] != '.' && board[i][j++]) // while the board's current coordinate is a letter, and while we iterate through the board's columns
		if (!board[i][j]) //if we get to the end of the row's columns and they're full of letters, move to the next row
		{
			i++; //move to the next row 
			j = 0; //start at the beginning of the next column
		}
	while (board[i] && piece[k]) //while we iterate through the board's rows at its first column spot and the current piece's index
	{
		// IF STATEMENT SHOULD BE MADE INTO FUNCTION
		if (piece[k] >= 'A' && piece[k] <= 'Z') //if we find a character in the current index
		{
			//MAYBE the actual copying can be placed in a function
			if (board[i][j] != '.') //if the current index of the board, does not equal a dot, we've filled the board and need to go back and increase it
				return (0);
			board[i][j] = piece[k]; //otherwise, place the current character
			c++; //increase the char count
			if (c == 4) //if the # of characters is four, a tetrimino, then return 1
				return (1);
		}
		j++; // if we dont find a char in the first line of the piece that we're looking at, move ahead to a new line
		if (piece[k] == '\n')
			repos(board, &i, &j); //move the current base string index that we're at to another row and column
		if (!board[i][j]) //????
		{
			i++;
			j = 0;
		}
		k++; //increase the index of the current PIECE we're on in the while loop
	}
	return (0);
}

int main() {
	char **pieces = (char**)malloc(sizeof(char*) * 6);
	char *board = builder(g_size);
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
