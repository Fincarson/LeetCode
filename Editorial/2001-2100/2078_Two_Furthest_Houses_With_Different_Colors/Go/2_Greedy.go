func maxDistance(colors []int) int {
	n := len(colors)
	ans := 0
	for i := 0; i < n-1; i++ {
		if colors[i] != colors[n-1] {
			d := i
			if n-1-i > d {
				d = n - 1 - i
			}
			if d > ans {
				ans = d
			}
		}
	}
	return ans
}
