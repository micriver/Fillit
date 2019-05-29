#include <stdlib.h>
#include <stdio.h>
#include "fillit.h"

int g_size = 2; //start out @ 2 for the smallest possible square piece board

void    repos(char *board, int *i) //dereferences the values in the stack and doesn't return anything
{
	while (*i < (g_size * 4))
	{
		if (board[*i] == '\n')
		{
			*i += 1;
			break ;
		}
		*i += 1;
	}
}

int		place_check(char *piece, char *board)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while(piece[i] && board[x])
	{
		if(board[x] == '.' && peice[i] >= 'A' && piece[i] <= 'Z')
			board[x] = piece[i];
		if (piece[i] == '.' || (piece[i + 1] == '.' && piece[i] < '\n'))
			i++;
		x++;
	}


int		place(char *piece, char *board, char letter)
{
	int i;
	int k;
	int charcount;
	(void)letter;

	i = 0;
	k = 0;
	charcount = 0;
	while (piece[k] && piece[k] < 64) //iterate through the piece until we get to a letter
		k++;
	while (board[i] != '.' && board[i]) //this is for when the board is full of pieces from prior loops
		i++;
	while (board[i] && piece[k]) //while we iterate through the board's indexes and the current piece's indexes
	{
		if (piece[k] >= 'A' && piece[k] <= 'Z' && board[i] != '.')
			return (0);
		if (piece[k] >= 'A' && piece[k] <= 'Z' && board[i] == '.')
		{
			board[i] = piece[k];
			charcount++;
		}
		if(charcount == 4)
			return (1);
		if (piece[k] == '\n')
			repos(board, &i);
		k++;
	}
	return (0);
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
	// pieces[2] = "....\n....\nCC..\nCC..\n";
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
