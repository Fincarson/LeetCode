func isTrionic(nums []int) bool {
	n := len(nums)
	if nums[0] >= nums[1] {
		return false
	}
	count := 1
	for i := 2; i < n; i++ {
		if nums[i-1] == nums[i] {
			return false
		}
		if (nums[i-2]-nums[i-1])*(nums[i-1]-nums[i]) < 0 {
			count++
		}
	}
	return count == 3
}
