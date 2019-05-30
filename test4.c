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

int		piece_try(char *board, char *piece, int *i, char letter)
{
	int k;
	int *ptr;

	k = 0;
	*ptr = *i;
	while (piece[k])
	{
		if (piece[k] == letter)
		{
			if (board[*ptr] != '.')
				return (0);
			else
			{
				// k++;
				*ptr += 1;
			}
		}
		k++;
	}
	return (1);
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

/*
 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int g_size = 2;

void        pickup(char *board, char c)
{
    int i;

    i = 0;
    while (board[i])
    {
        if (board[i] == c)
        {
            board[i] = '.';
        }
        i++;
    } 
}

//1. placing the pieces on the board
int       place(char *pieces, char *board, letter)
{
  int i;
  
  i = 0;
  while (board[i])
  {
    if (i = (!board_index(board, piece, &i))
      return (0); //<--- means we'll have to expand the board if the next piece doesn't work
    //2. board_index-loop through board and return index where piece fits
      //3. piece_audit-find board index that complete piece will fit
    //4. copy the piece onto the board
    if (piece_copy(char *board, char *piece, int *i))
      return (1);
    i++;
  }
  return (0);
}

//returns board index to start copying piece
int       board_index(char *board, char *piece, int *i)
{   
  while(board[*i] != '.' && board[*i])
  {
    if (board[*i] == '\n')
      i++;
    if (board[*i] == '.' && (!piece_audit(board, piece, &i)))
      i++;
    else
      return (i);
  }
  return (0);
}

//audition pieces for placement
int       piece_audit(char *board, char *piece, int *i, char letter)
{
  int k;
  int charcount;
  int *ptr;
  
  k = 0;
  charcount = 0;
  ptr = i;
  while (piece[k] && piece[k] < 64) //find first occurence of letter
    k++;
  while (piece[k] && board[ptr]) //loop through piece while at first letter
  {
    if (piece[k] == letter && board[ptr] == '.') //move forward in board if we find letter
    {
      *ptr += 1;
      return (charcount == 4) ? 1 : charcount++;
    }
    else if (piece[k] == '.' || board[ptr] != '.' || board[ptr] == '.')
      *ptr += 1;
    else if (piece[k] == '\n')
      repos(board, *ptr);
    k++
  }
  return (0);
}

void      piece_copy(char *board, char *piece, int *i)
{
  int k;
  int *ptr;
  //int charcount;
  
  k = 0;
  ptr = i;
  //charcount = 0;
  while (piece[k] && piece[k] < 64) //find first occurence of letter
    k++;
  while (piece[k] && board[ptr])
  {
    if (piece[k] >= 'A' && piece[k] <= 'Z')
    {
      board[ptr] = piece[k];
      //(charcount == 4) ? break : charcount++;
    }
    k++
    ptr += 1;
  }
}

int        backtrack(char *board, char **pieces, char letter)
{
    int        i;

    i = -1;
    // printf("This is what the board looks like right now:\n%s\n", board);
    // printf("Current piece to be placed:\n%s\n", pieces[0]);
    while (board[i] != '\n' && board[++i])
    {
        {
            if (!place(pieces[0], board, letter) || !solve(board, &pieces[1]))
                pickup(board, letter);
            else
                return (1);
        }
    }
    return (0);
}

int        solve(char *board, char **pieces)
{
    int        i;
    char    letter;

    i = -1;
    letter = '\0';
    if (!pieces[0]) //if we're at the NULL piece in the 2D array - the end...
        return (1);
    while (pieces[0][++i])
    {
        if (pieces[0][i] >= 64)
        {
            letter = pieces[0][i];
            break ;
        }
    }
    return (backtrack(board, pieces, letter)) ? 1 : 0;
}


char    *builder(int g_size)
{
    int        i;
    char    *board;

    i = 0;
    board = (char *)malloc(sizeof(char *) * (g_size * (g_size + 1)));
    while (i < (g_size * (g_size + 1)))
    {
        if ((i + 1) % (g_size + 1) == 0)
            board[i] = '\n';
        else
            board[i] = '.';
        i++;
    }
    board[i] = '\0';
    return (board);
}

int main() {
    char **pieces = (char**)malloc(sizeof(char*) * 6);
    char **board = builder(g_size);
    pieces[0] = "A...\nA...\nA...\nA...\n";
    pieces[1] = "...B.\n.BBB\n....\n....\n";
    //pieces[2] = "C...\nC...\nCC..\n....\n";
    //pieces[3] = "D...\nD...\nDD..\n....\n";
    //pieces[4] = "..EE\n.EE.\n....\n....\n";
    // pieces[5] = "....\n....\n..FF\n..FF\n";
    pieces[2] = NULL;
    while (!solve(board, pieces)) {
        g_size++;
        board = builder(g_size);
    }
    for (int i = 0; board[i]; i++)
        printf("%s", board[i]);
    return (0);
}
*/