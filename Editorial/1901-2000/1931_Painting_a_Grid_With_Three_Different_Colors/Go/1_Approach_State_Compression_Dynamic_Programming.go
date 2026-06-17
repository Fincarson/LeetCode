const mod = 1000000007

func colorTheGrid(m int, n int) int {
	// Hash mapping stores all valid coloration schemes for a single row that
	// meet the requirements
	valid := make(map[int][]int)

	// Enumerate masks that meet the requirements within the range [0, 3^m)
	maskEnd := int(math.Pow(3, float64(m)))
	for mask := 0; mask < maskEnd; mask++ {
		color := make([]int, m)
		mm := mask
		for i := 0; i < m; i++ {
			color[i] = mm % 3
			mm /= 3
		}
		check := true
		for i := 0; i < m-1; i++ {
			if color[i] == color[i+1] {
				check = false
				break
			}
		}
		if check {
			valid[mask] = color
		}
	}

	// Preprocess all (mask1, mask2) binary tuples, satisfying mask1 and mask2
	// When adjacent rows, the colors of the two cells in the same column are
	// different
	adjacent := make(map[int][]int)
	for mask1 := range valid {
		for mask2 := range valid {
			check := true
			for i := 0; i < m; i++ {
				if valid[mask1][i] == valid[mask2][i] {
					check = false
					break
				}
			}
			if check {
				adjacent[mask1] = append(adjacent[mask1], mask2)
			}
		}
	}

	f := make(map[int]int)
	for mask := range valid {
		f[mask] = 1
	}
	for i := 1; i < n; i++ {
		g := make(map[int]int)
		for mask2 := range valid {
			for _, mask1 := range adjacent[mask2] {
				g[mask2] = (g[mask2] + f[mask1]) % mod
			}
		}
		f = g
	}

	ans := 0
	for _, num := range f {
		ans = (ans + num) % mod
	}
	return ans
}
