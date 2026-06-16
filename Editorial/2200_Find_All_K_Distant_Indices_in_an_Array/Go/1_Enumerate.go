func findKDistantIndices(nums []int, key int, k int) []int {
	var res []int
	n := len(nums)
	// traverse number pairs
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if nums[j] == key && abs(i-j) <= k {
				res = append(res, i)
				break // early termination to prevent duplicate addition
			}
		}
	}
	return res
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
