func buildArray(nums []int) []int {
	n := len(nums)
	// Build the final value on the first iteration
	for i := 0; i < n; i++ {
		nums[i] += 1000 * (nums[nums[i]] % 1000)
	}
	// Modified to final value on the second iteration
	for i := 0; i < n; i++ {
		nums[i] /= 1000
	}
	return nums
}
