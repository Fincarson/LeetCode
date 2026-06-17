func countValidSelections(nums []int) int {
	n := len(nums)
	sum := 0
	for _, x := range nums {
		sum += x
	}
	ans, leftSum, rightSum := 0, 0, sum
	for i := 0; i < n; i++ {
		if nums[i] == 0 {
			if leftSum-rightSum >= 0 && leftSum-rightSum <= 1 {
				ans++
			}
			if rightSum-leftSum >= 0 && rightSum-leftSum <= 1 {
				ans++
			}
		} else {
			leftSum += nums[i]
			rightSum -= nums[i]
		}
	}
	return ans
}
