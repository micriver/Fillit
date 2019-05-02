/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_ult_solve.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrivera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:18:40 by mrivera           #+#    #+#             */
/*   Updated: 2018/10/02 23:11:01 by mrivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		valid_number(char **sudoku, int num, int row, int col)
{
	int x;
	int y;
	int pos_x;
	int pos_y;

	pos_x = 0;
	pos_y = 0;
	x = 0;
	y = 0;
	while(x < 9)
	{
		if(sudoku[row][x] == num) //we're checking the columns here x's are each cell
			return (0); //ZERO means its not valid
		x++;
	}
	while(y < 9)		
	{
		if(sudoku[y][col] == num) //we changed to looking at the column values from the top down
			return (0); //ZERO means its not valid
		y++; // then iterating down the columns
	}
	x = (row / 3) * 3; //this is to reset back to the top left columns
	y = (col / 3) * 3; 
	while(pos_x < 3)
	{
		while(pos_y < 3)
		{
			if(sudoku[x + pos_x][y + pos_y] == num) // if there is a number there it returns a zero
					return (0);
			pos_y++;
		}
		pos_x++;
	}
	return (1);	
}

int		sudoku_ult_solve(char **sudoku, int row, int col)
{
	int num;
	
	num = 1; //this is 1 because sudoku because can only have 1-9 
	if(col >= 9)
	{
		row++; //this is incrementing to a new line if the algorithm iterates through 9 columns
		col = 0; //starting from the zero position
	}	
	if(row >= 9) //this is the end of the sudoku puzzle where you return to the beginning 
		return (1);
	if(sudoku[row][col] == 0)
	{
		while(num <= 9) //this is where backtracking starts
		{
			if(valid_number(sudoku, num, row, col))
			{
				sudoku[row][col] = num; //we are trying each number here in each box
				if(sudoku_ult_solve(sudoku, row, col + 1))
					return (1);
			}
			num++;
		}
		sudoku[row][col] = 0; //this is the backtracking, to reset to where you were at
		return (0);	
	}
	else
		return (sudoku_ult_solve(sudoku, row, col + 1)); // we are visually going from L to R
}
