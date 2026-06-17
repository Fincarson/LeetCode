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
	dp := make([][26][26]int, n)

	for i := 0; i < n; i++ {
		for j := 0; j < 26; j++ {
			for k := 0; k < 26; k++ {
				dp[i][j][k] = 1 << 30
			}
		}
	}

	firstChar := int(word[0] - 'A')
	for i := 0; i < 26; i++ {
		dp[0][i][firstChar] = 0
		dp[0][firstChar][i] = 0
	}

	for i := 1; i < n; i++ {
		cur := int(word[i] - 'A')
		prev := int(word[i-1] - 'A')
		d := getDistance(prev, cur)

		for j := 0; j < 26; j++ {
			dp[i][cur][j] = min(dp[i][cur][j], dp[i-1][prev][j]+d)
			dp[i][j][cur] = min(dp[i][j][cur], dp[i-1][j][prev]+d)

			if prev == j {
				for k := 0; k < 26; k++ {
					d0 := getDistance(k, cur)
					dp[i][cur][j] = min(dp[i][cur][j], dp[i-1][k][j]+d0)
					dp[i][j][cur] = min(dp[i][j][cur], dp[i-1][j][k]+d0)
				}
			}
		}
	}

	ans := 1 << 30
	for i := 0; i < 26; i++ {
		for j := 0; j < 26; j++ {
			ans = min(ans, dp[n-1][i][j])
		}
	}
	return ans
}
