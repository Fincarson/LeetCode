func isGood(nums []int) bool {
	sort.Ints(nums)
	n := len(nums) - 1
	for i := 0; i < n; i++ {
		if nums[i] != i+1 {
			return false
		}
	}
	return nums[n] == n
}
