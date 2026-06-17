func reverseSubmatrix(grid [][]int, x int, y int, k int) [][]int {
	for i0, i1 := x, x+k-1; i0 < i1; i0, i1 = i0+1, i1-1 {
		for j := y; j < y+k; j++ {
			grid[i0][j], grid[i1][j] = grid[i1][j], grid[i0][j]
		}
	}
	return grid
}
