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

int		place(char *piece, char *board, char letter)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (piece[k] && piece[k] < 64) //iterate through the piece until we get to a letter
		k++;
	while (board[i] != '.' && board[i]) //this is for when the board is full of pieces from prior loops
		i += k;
	while (board[i] && piece[k]) //while we iterate through the board's indexes and the current piece's indexes
	{
		if (piece[k] >= 'A' && piece[k] <= 'Z' && board[i] != '.') //if we find a character in the current piece's index
				return (0);
		if (piece[k] >= 'A' && piece[k] <= 'Z' && board[i] == '.') //if the current index of the board, does not equal a dot, we've filled the board and need to go back and increase the g_size
			board[i] = piece[k]; //otherwise, place the current character at the board's current empty index
		if (piece[k] == '\n')
			repos(board, &i); //move the current base string index that we're at to another row and column on the board following the index of the piece's board
		k++; //increase the index of the current PIECE we're on in the while loop
	}
	if (!placement_check(board, letter))
		return (0);
	return (1);
	// return (placement_check(board, letter)) ? 1 : 0;
}

int		placement_check(char *piece, char c)
{
	int		i;
	int		sidecount;
	int		charcount;

	i = 0;
	sidecount = 0;
	charcount = 0;
	while (piece[i])
	{
		if (piece[i] == c)
		{
			(piece[i + 1] == c) ? sidecount++ : sidecount;
			(piece[i + (g_size + 1)] == c) ? sidecount++ : sidecount;
			(piece[i - 1] == c) ? sidecount++ : sidecount;
			(piece[i - (g_size + 1)] == c) ? sidecount++ : sidecount;
			charcount++;
			if(charcount == 4)
				break ;
		}
		i++;
	}
	return ((sidecount == 6 || sidecount == 8) && charcount == 4) ? 1 : 0;
}

int main() {
	char **pieces = (char**)malloc(sizeof(char*) * 6);
	char *board = builder(g_size);
	pieces[0] = "A...\nA...\nA...\nA...\n";
	pieces[1] = "..B.\n.BBB\n....\n....\n";
	// pieces[2] = "C...\nC...\nCC..\n....\n";
	// pieces[3] = "D...\nD...\nDD..\n....\n";
	// pieces[4] = "..EE\n.EE.\n....\n....\n";
	// pieces[5] = "....\n....\n..FF\n..FF\n";
	pieces[2] = NULL;
	while (!solve(board, pieces)) 
	{
		g_size++;
		board = builder(g_size);
	}
	// for (int i = 0; board[i]; i++)
	// 	printf("%c", board[i]);
	// free(board);
	return (0);
}
