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
	
