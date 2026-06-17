func findFinalValue(nums []int, original int) int {
	set := make(map[int]bool)
	for _, num := range nums {
		set[num] = true
	}
	for set[original] {
		original *= 2
	}
	return original
}
