#include <stdlib.h>
#include <stdio.h>
#include "fillit.h"

int g_size = 3;

int		place(char *piece, char **board, int j)
{
	int i;
	int c;
	int k;
	int x;

	i = 0;
	c = 0;
	k = 0;
	while (piece[k] && piece[k] < 64)
		k++;
	while (board[i][j] != '.' && board[i][j++])
	{
		if (!board[i][j])
		{
			i++;
			j = 0;
		}
	}
	while (board[i] && piece[k])
	{
		if (piece[k] >= 'A' && piece[k] <= 'Z' && board[i][j] != '.')
			return (0);
		if (piece[k] >= 'A' && piece[k] <= 'Z' && board[i][j] == '.')
		{
			board[i][j] = piece[k];
			c++;
		}
		if (c == 4)
			return (1);
		j++;
		if (piece[k] == '\n')
		{
			x = 0;
			while (x++ < g_size - 4)
			{
				if (!board[i][j])
				{
					i++;
					j = 0;
				}
				j++;
			}
		}
		k++;
		if (!board[i][j])
		{
			i++;
			j = 0;
		}
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
