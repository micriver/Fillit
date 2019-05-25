#include <stdlib.h>
#include <stdio.h>
#include "fillit.h"

int g_size = 2; //start out @ 2 for the smallest possible square piece board

void    repos(char *board, int *i) //dereferences the values in the stack and doesn't return anything
{
	while (*i < (g_size * 4))
	{
		// if (board[*i] == '.') //when we get to a terminating char for our board
		// 	*i += 1; //move down a row
		if (board[*i] == '\n')
		{
			*i += 1;
			break ;
		}
		*i += 1;
	}
}

int		place(char *piece, char *board, int charcount)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (piece[k] && piece[k] < 64) //iterate through the piece until we get to a letter
		k++;
	while (board[i] != '.' && board[i]) //thi`s is for when the board is full of pieces from prior loops
		i++;
	while (board[i] && piece[k]) //while we iterate through the board's indexes and the current piece's indexes
	{
		if (piece[k] >= 'A' && piece[k] <= 'Z') //if we find a character in the current piece's index
		{
			if (board[i] != '.') //if the current index of the board, does not equal a dot, we've filled the board and need to go back and increase the g_size
				return (0);
			board[i] = piece[k]; //otherwise, place the current character at the board's current empty index
			(charcount == 4) ? 1 : charcount++; //increase the charcount if its not four, otherwise, exit placement with a TRUE confirmation
		}
		if (piece[k] == '\n')
			repos(board, &i); //move the current base string index that we're at to another row and column on the board following the index of the piece's board
		k++; //increase the index of the current PIECE we're on in the while loop
		// if (board[i + 1] == '\0' && charcount < 4) 
		// {
		// 	g_size++;
		// 	board = builder(g_size);
		// }
	}
	return (0);
}

/* {
	int i;
	int k;

	i = 0;
	k = 0;
	while (piece[k] && piece[k] < 64) // iterate through the piece, and if the piece is not a letter
		k++;
	while (board[i][j] != '.' && board[i][j++]) // while the board's current coordinate is a letter, and while we iterate through the board's columns
		if (!board[i][j]) //if we get to the end of the row's columns and they're full of letters, move to the next row
		{
			i++; //move to the next row 
			j = 0; //start at the beginning of the next column
		}
	while (board[i] && piece[k]) //while we iterate through the board's rows at its first column spot and the current piece's index
	{
		if (piece[k] >= 'A' && piece[k] <= 'Z') //if we find a character in the current index
		{
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
} */


int main() {
	char **pieces = (char**)malloc(sizeof(char*) * 6);
	char *board = builder(g_size);
	pieces[0] = "A...\nA...\nA...\nA...\n";
	// pieces[1] = "...B.\n.BBB\n....\n....\n";
	// pieces[2] = "C...\nC...\nCC..\n....\n";
	// pieces[3] = "D...\nD...\nDD..\n....\n";
	// pieces[4] = "..EE\n.EE.\n....\n....\n";
	// pieces[5] = "....\n....\n..FF\n..FF\n";
	pieces[1] = NULL;
	while (!solve(board, pieces)) 
	{
		g_size++;
		free(board);
		board = builder(g_size);
	}
	for (int i = 0; board[i]; i++)
		printf("%c", board[i]);
	return (0);
}
