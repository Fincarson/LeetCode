const INF = 1e9

func validSubarraySplit(nums []int) int {
	n := len(nums)
	dp := make([]int, n+1)
	for i := 0; i <= n; i++ {
		dp[i] = INF
	}
	dp[0] = 0
	for i := 1; i <= n; i++ {
		for j := 1; j <= i; j++ {
			if gcd(nums[i-1], nums[j-1]) > 1 {
				dp[i] = min(dp[i], dp[j-1]+1)
			}
		}
	}
	if dp[n] == INF {
		return -1
	}
	return dp[n]
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
