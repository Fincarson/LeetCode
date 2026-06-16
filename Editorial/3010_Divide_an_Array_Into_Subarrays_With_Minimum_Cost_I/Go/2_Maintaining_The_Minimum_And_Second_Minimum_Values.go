func minimumCost(nums []int) int {
	first := int(^uint(0) >> 1)
	second := int(^uint(0) >> 1)

	for i := 1; i < len(nums); i++ {
		x := nums[i]
		if x < first {
			second = first
			first = x
		} else if x < second {
			second = x
		}
	}
	return nums[0] + first + second
}
