To place N Queens in a NxN board in such a way that no queens attack eacj other.
Queens attack each other when: 
1. They are in same row or column 
2. They are in same diagonal

Algorithm: `Solve(int board[N][N], int column)

if all queens are placed i.e `col>=N` condition is met 

	return true or display the non-attacking positions of the queen
	
for ( every possible choice among the rows in this column)

	make that choice and then recursively try to place the rest of the queen
	
	if recursion is successful
	
		return true
		
	if !successful 
	
		remove queen and try another row in this column
		
if all rows have been tried and nothing worked 

	return false to trigger backtracking
	
`
