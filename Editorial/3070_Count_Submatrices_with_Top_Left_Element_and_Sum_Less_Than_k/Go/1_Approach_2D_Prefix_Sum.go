func countSubmatrices(grid [][]int, k int) int {
	m := len(grid)
	n := len(grid[0])
	cols := make([]int, n)
	res := 0

	for i := 0; i < m; i++ {
		rows := 0
		for j := 0; j < n; j++ {
			cols[j] += grid[i][j]
			rows += cols[j]
			if rows <= k {
				res++
			}
		}
	}

	return res
}
