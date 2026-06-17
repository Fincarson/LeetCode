func maximumJumps(nums []int, target int) int {
	n := len(nums)
	dp := make([]int, n)
	for i := range dp {
		dp[i] = math.MinInt32
	}
	dp[0] = 0

	for i := 1; i < n; i++ {
		for j := 0; j < i; j++ {
			if abs(nums[j]-nums[i]) <= target {
				dp[i] = max(dp[i], dp[j]+1)
			}
		}
	}

	if dp[n-1] < 0 {
		return -1
	}
	return dp[n-1]
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
