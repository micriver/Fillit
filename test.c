#include <stdlib.h>
#include <stdio.h>

int size = 3;

int		drop(char *piece, char **board, int j)
{
	int i;
	int c;
	int k;
	int x;

	i = 0;
	c = 0;
	k = 0;
	while (piece[k] && piece[k] < 64) //ie, a letter above 64 in ascii
		k++;
	while (board[i][j] != '.' && board[i][j]) //while we're at a character from the previous piece's placement 
	{
		j++; //iterate through the board's chars
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
			while (x < size - 4)
			{
				if (!board[i][j])
				{
					i++;
					j = 0;
				}
				j++;
				x++;
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
			for (int x = 0; x < size - 4; x++) {
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


void	pickup(char **board, char c)
{
	int i;
	int j;

	i = 0;
	while (board[i])
	{
		j = 0;
		while (board[i][j])
		{
			if (board[i][j] == c)
				board[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		solve(char **board, char **pieces)
{
	int		i;
	int		j;
	char	letter;

	i = -1;
	if (!pieces[0])
		return (1);
	while (pieces[0][++i])
	{
		if (pieces[0][i] >= 64)
		{
			letter = pieces[0][i];
			break ;
		}
	}
	i = -1;
	while (board[++i])
	{
		j = -1;
		while (board[i][++j])
		{
			if (!drop(pieces[0], board, j) || !solve(board, &pieces[1]))
				pickup(board, letter);
			else
				return (1);
		}
	}
	return (0);
}

char	**builder(int size)
{
	int		i;
	int		j;
	char	**board;

	i = 0;
	size += 1;
	board = (char **)malloc(sizeof(char *) * size);
	while (i < (size - 1))
	{
		board[i] = (char*)malloc(sizeof(char) * size + 1);
		j = 0;
		while (j < (size - 1))
		{
			board[i][j] = '.';
			j++;
		}
		board[i][size - 1] = '\n';
		board[i][size] = '\0';
		i++;
	}
	board[size - 1] = NULL;
	return (board);
}

int main() {
	char **pieces = (char**)malloc(sizeof(char*) * 6);
	char **board = builder(size);
	pieces[0] = "A...\nA...\nA...\nA...\n";
	pieces[1] = "...B.\n.BBB\n....\n....\n";
	pieces[2] = "C...\nC...\nCC..\n....\n";
	pieces[3] = "D...\nD...\nDD..\n....\n";
	pieces[4] = "..EE\n.EE.\n....\n....\n";
	pieces[5] = NULL;
	while (!solve(board, pieces)) {
		size++;
		board = builder(size);
	}
	for (int i = 0; board[i]; i++)
		printf("%s", board[i]);
	return (0);
}
