func minBitwiseArray(nums []int) []int {
	result := make([]int, len(nums))

	for i, original := range nums {
		candidate := -1

		for j := 1; j < original; j++ {
			if (j | (j + 1)) == original {
				candidate = j
				break
			}
		}

		result[i] = candidate
	}

	return result
}
