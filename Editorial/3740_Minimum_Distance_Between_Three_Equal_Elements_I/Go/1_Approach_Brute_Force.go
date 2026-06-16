func minimumDistance(nums []int) int {
	n := len(nums)
	ans := n + 1

	for i := 0; i < n-2; i++ {
		for j := i + 1; j < n-1; j++ {
			if nums[i] != nums[j] {
				continue
			}
			for k := j + 1; k < n; k++ {
				if nums[j] == nums[k] {
					if dist := k - i; dist < ans {
						ans = dist
					}
					break
				}
			}
		}
	}

	if ans == n+1 {
		return -1
	}
	return ans * 2
}
