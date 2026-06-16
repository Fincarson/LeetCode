func findFinalValue(nums []int, original int) int {
	sort.Ints(nums)
	for _, num := range nums {
		if original == num {
			original *= 2
		}
	}
	return original
}
