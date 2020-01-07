#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 10

/*
Fn checks the cell which has 0 i.e unassigned element and returns that row and column for the unassigned index
*/
bool findUnassignedRowCol(int grid[MAX][MAX], int *row, int *col)  // reference to row and col variable in main fn
{
	for(*row=0;*row<9; (*row)++){
	        for(*col =0; *col<9;(*col)++){
	            if(grid[*row][*col] == 0)
	            	return true;
	        }
	        }
	return false;
}
/*
usedInRow() fn checks if the element 'num' is already present in it or not
*/
bool usedInRow(int grid[MAX][MAX], int row, int num)
{
	for(int col = 0; col < 9; col ++)
		if(grid[row][col] == num)
			return true;
	return false;
}
// this fn checks if the element num is already present in the column
bool usedInCol(int grid[MAX][MAX], int col, int num)
{
	for(int row = 0; row < 9; row ++)
		if(grid[row][col] == num)
			return true;
	return false;
}
//usedInBlock() fn checks if the element 'num' is already present in the 3x3 block
bool usedInBlock(int grid[MAX][MAX] , int blockStartRow, int blockStartCol,int num)
{
	for(int i=0;i<3;i++)
	        for(int j=0; j<3;j++)
	        	if(grid[blockStartRow + i][blockStartCol+j] == num)
	        		return true;
	return false;
}
// noConflict() fn returns true if all usedInBlock()fn, usedInRow() and usedInCol() fn returns false
bool noConflict(int grid[MAX][MAX],int row, int col, int num)
{
	return !usedInRow(grid,row,num) && !usedInCol(grid,col ,num) && !usedInBlock(grid, row - row %3, col -col%3, num);
}
/*
Takes a partially filled grid and attempts to assign values to all unassigned locations in such a way to meet the requirements for SUDOKU solution (i.e. non duplicate soln)

Find unassigned location with the grid and consider all digit from 1 to 9 in a loop.

If a digit is found that has no existing conflicts tentatively assign it and recur to other to fill rest of the grid.
if Success, our sudoku is solved else unmard that postion in the grid and try again.
*/
bool solveSudoku(int grid[MAX][MAX])
{
	int row,col;
	if(!findUnassignedRowCol(grid,&row,&col))
		return true;
	for(int num=1;num<=9;num++)
	{
		if(noConflict(grid,row,col,num))
		{
			grid[row][col] = num;
			if(solveSudoku(grid))
				return true;
			grid[row][col] = 0;
		}
	}
	return false;
}
void display(int grid[MAX][MAX])
{
	for(int i=0;i <9;i++){
		for(int j =0 ; j<9;j++)
			printf("%d ",grid[i][j]);
		printf("\n");
	}
	printf("\n");
}
int main() {
	int t;int grid[MAX][MAX];
	scanf("%d",&t);
	while(t--)
	{
	    for(int i=0;i<9;i++)
	        for(int j=0; j<9;j++)
	            scanf("%d",&grid[i][j]);
	   //if(!
	   if(!solveSudoku(grid))
	    printf("NO SOLUTION");
	   else
	   	printf("Solution is:\n") ;
	   display(grid);
	}
	return 0;
}
