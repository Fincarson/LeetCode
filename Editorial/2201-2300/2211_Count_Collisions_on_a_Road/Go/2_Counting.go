func countCollisions(directions string) int {
	n := len(directions)
	l, r := 0, n-1

	for l < n && directions[l] == 'L' {
		l++
	}

	for r >= l && directions[r] == 'R' {
		r--
	}

	res := 0
	for i := l; i <= r; i++ {
		if directions[i] != 'S' {
			res++
		}
	}
	return res
}
