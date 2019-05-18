#include <stdlib.h>
#include <stdio.h>

int size = 3;

int    drop(char *piece, char **board, int j)
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
}

void	pickup(char** board, char c) {
	for (int i = 0; board[i]; i++)
		for (int j = 0; board[i][j]; j++)
			if (board[i][j] == c)
				board[i][j] = '.';
}

int solve(char **board, char **pieces) {
	char letter;
	if (!pieces[0])
		return (1);
	for (int i = 0; pieces[0][i]; i++)
		if (pieces[0][i] >= 64) {
			letter = pieces[0][i];
			break ;
		}
	for (int i = 0; board[i]; i++) {
		for (int j = 0; board[i][j]; j++) {
			if (!drop(pieces[0], board, j) || !solve(board, &pieces[1]))
				pickup(board, letter);
			else
				return (1);
		}
	}
	return (0);
}

char **builder(int size) {
    size += 1;
    char **board = (char**)malloc(sizeof(char*) * size);
        for (int i = 0; i < size - 1; i++) {
            board[i] = (char*)malloc(sizeof(char) * size + 1);
            for (int j = 0; j < size - 1; j++)
                board[i][j] = '.';
            board[i][size - 1] = '\n';
            board[i][size] = '\0';
        }
    board[size - 1] = NULL;
    return (board);
}

int main() {
	char **pieces =  (char**)malloc(sizeof(char*) * 6);
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
