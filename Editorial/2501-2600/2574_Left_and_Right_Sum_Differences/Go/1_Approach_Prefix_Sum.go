func leftRightDifference(nums []int) []int {
	n := len(nums)
	ans := make([]int, n)

	leftSum := 0
	for i := 0; i < n; i++ {
		ans[i] = leftSum
		leftSum += nums[i]
	}

	rightSum := 0
	for i := n - 1; i >= 0; i-- {
		ans[i] = abs(ans[i] - rightSum)
		rightSum += nums[i]
	}

	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
