func getDistance(p, q int) int {
	x1, y1 := p/6, p%6
	x2, y2 := q/6, q%6
	return abs(x1-x2) + abs(y1-y2)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func minimumDistance(word string) int {
	n := len(word)
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, 26)
		for j := range dp[i] {
			dp[i][j] = 1 << 30
		}
	}
	for j := 0; j < 26; j++ {
		dp[0][j] = 0
	}

	for i := 1; i < n; i++ {
		cur := int(word[i] - 'A')
		prev := int(word[i-1] - 'A')
		d := getDistance(prev, cur)

		for j := 0; j < 26; j++ {
			dp[i][j] = min(dp[i][j], dp[i-1][j]+d)
			if prev == j {
				for k := 0; k < 26; k++ {
					d0 := getDistance(k, cur)
					dp[i][j] = min(dp[i][j], dp[i-1][k]+d0)
				}
			}
		}
	}

	ans := 1 << 30
	for j := 0; j < 26; j++ {
		ans = min(ans, dp[n-1][j])
	}
	return ans
}
