func areSimilar(mat [][]int, k int) bool {
	m := len(mat)
	n := len(mat[0])
	k %= n

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if mat[i][j] != mat[i][(j+k)%n] {
				return false
			}
		}
	}
	return true
}
