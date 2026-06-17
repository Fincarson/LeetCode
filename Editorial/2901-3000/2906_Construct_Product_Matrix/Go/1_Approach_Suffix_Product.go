func constructProductMatrix(grid [][]int) [][]int {
	const MOD = 12345
	n, m := len(grid), len(grid[0])
	p := make([][]int, n)
	for i := range p {
		p[i] = make([]int, m)
	}

	suffix := int64(1)
	for i := n - 1; i >= 0; i-- {
		for j := m - 1; j >= 0; j-- {
			p[i][j] = int(suffix)
			suffix = (suffix * int64(grid[i][j])) % MOD
		}
	}

	prefix := int64(1)
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			p[i][j] = int((int64(p[i][j]) * prefix) % MOD)
			prefix = (prefix * int64(grid[i][j])) % MOD
		}
	}

	return p
}
