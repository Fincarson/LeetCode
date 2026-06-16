func maximumJumps(nums []int, target int) int {
	n := len(nums)
	memo := make([]int, n)
	for i := range memo {
		memo[i] = math.MinInt32
	}

	var dfs func(int) int
	dfs = func(i int) int {
		if i == n-1 {
			return 0
		}
		if memo[i] != math.MinInt32 {
			return memo[i]
		}

		res := math.MinInt32
		for j := i + 1; j < n; j++ {
			if abs(nums[i]-nums[j]) <= target {
				res = max(res, dfs(j)+1)
			}
		}
		memo[i] = res
		return res
	}

	ans := dfs(0)
	if ans < 0 {
		return -1
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
