#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int N;
int solCount =0;
bool solve(int board[N][N], int col);
bool rowIsClear(int board[N][N], int row, int col);
bool upperDiagIsClear(int board[N][N], int row, int col);
bool lowerDiagIsClear(int board[N][N], int row, int col);
bool isSafe(int board[N][N],int row, int col);
void clearBoard(int board[N][N]);
void displayBoard(int board[N][N]);
int main(void)
{
	
	printf("Enter the size of NXN board: ");
	scanf("%d",&N);
	int board[N][N];
	clearBoard(board);
	if(!solve(board,0))
		printf("\nNo solution was found\n");
	return 0;
}
//to check if any queen is already present in the row    
bool rowIsClear(int board[N][N], int row, int col)
{
	for(int i=0; i< col; i++)
		if(board[row][i]==1)
			return false;
	return true;
}
// check the northwest diagonal for any queen already present
bool lowerDiagIsClear(int board[N][N], int row, int col)
{
	int i,j;
	for(i = row,j = col; i>=0 && j>=0; i--,j--)
		if(board[i][j] == 1)
			return false;
	return true;
}
//check the southwest diagonal for any queen already present
bool upperDiagIsClear(int board[N][N], int row, int col)
{
	int i,j;
	for(i= row,j=col; i<=N && j>=0;i++,j--)
		if(board[i][j] == 1)
			return false;
	return true;
}
//first fn to be called by main
//if all queens are placed i.e `col>=N` condition is met 
//	return true or display the non-attacking positions of the queen
//for ( every possible choice among the rows in this column)
//	make that choice and then recursively tryu to place the rest of the queen
//	if recursion is successful
//		return true
//	if !successful 
//		remove queen and try another row in this column
//if all rows have been tried and nothing worked 
//	return false to trigger backtracking
bool solve(int board[N][N], int col)
{
	static int flag = 0;
	if(col >=N)    // Here if we returned true than we wd get only 1 output instead we want multiple solutions then we will display each time cond 'col>=N' is fulfilled
	{
		flag =1;
		displayBoard(board);
		solCount++;  // increase solution count by 1
		return flag; // to indicate that flag is true and it has atleast 1 solution
	}
	for(int i=0; i<N;i++)
	{
		if(isSafe(board, i , col))
		{
			board[i][col]=1;
			solve(board,col+1);// if(solve(board,col+1)    
						//return true;     // if we had returned here then we wd have got only 1 result but we want multiple solutions
			board[i][col]=0;
		}
	}
	return flag;
}
// fn to check that all the necssary conditions for not attacking of queen is fulfilled
bool isSafe(int board[N][N], int row, int col)
{
	return rowIsClear(board, row, col) && upperDiagIsClear(board, row,col) && lowerDiagIsClear(board, row,col);
}
//Initializes each cell to zero
void clearBoard(int board[N][N])
{
	for(int i=0; i< N; i++)
		for(int j=0; j<N;j++)
			board[i][j]=0;
}
//displays the final non attacking positions of queen in a NXN board
void displayBoard(int board[N][N])
{
	printf("Solution: %d\n",solCount+1);
	for(int i=0; i<N;i++)
	{
		for(int j=0; j< N;j++)
		{
			if(board[i][j] == 1)
				printf("Q");
			else
				printf("#");
		}
		printf("\n");
	}
}
