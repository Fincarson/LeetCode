func distance(nums []int) []int64 {
	n := len(nums)
	groups := make(map[int][]int)
	for i := 0; i < n; i++ {
		groups[nums[i]] = append(groups[nums[i]], i)
	}
	res := make([]int64, n)
	for _, group := range groups {
		var total int64
		for _, idx := range group {
			total += int64(idx)
		}
		var prefixTotal int64
		for i, idx := range group {
			res[idx] = total - prefixTotal*2 + int64(idx)*int64(2*i-len(group))
			prefixTotal += int64(idx)
		}
	}
	return res
}
