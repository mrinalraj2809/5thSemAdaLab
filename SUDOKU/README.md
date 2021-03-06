Given a NxN unsolved Sudoku matrix find its solution using backtracking.


Pseudo Code: SOLVE(int grid[][])

//input: An NxN grid matrix 

// Output: An NxN solved grid matrix


	Find row, col of an unassigned cell

	if there is no conflict for digit at row, col

		assign digit to row, col and recursively try filling in rest of the grid
		
		if recursion is successful, return true   // means there is no unassigned cell left 
		
		if !successful, remove digit and try another
		
	if all digit have tried and nothing worked, return false to trigger backtracking

		

### Input:

1

3 0 6 5 0 8 4 0 0

5 2 0 0 0 0 0 0 0

0 8 7 0 0 0 0 3 1

0 0 3 0 1 0 0 8 0

9 0 0 8 6 3 0 0 5

0 5 0 0 9 0 6 0 0

1 3 0 0 0 0 2 5 0

0 0 0 0 0 0 0 7 4

0 0 5 2 0 6 3 0 0



### Output:

3 1 6 5 7 8 4 9 2

5 2 9 1 3 4 7 6 8

4 8 7 6 2 9 5 3 1

2 6 3 4 1 5 9 8 7

9 7 4 8 6 3 1 2 5

8 5 1 7 9 2 6 4 3

1 3 8 9 4 7 2 5 6

6 9 2 3 5 1 8 7 4

7 4 5 2 8 6 3 1 9


