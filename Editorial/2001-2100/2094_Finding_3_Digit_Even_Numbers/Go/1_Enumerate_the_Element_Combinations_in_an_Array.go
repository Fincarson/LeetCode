func findEvenNumbers(digits []int) []int {
	nums := make(map[int]bool)
	n := len(digits)
	// Traverse the indices of three digits
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				// Determine whether it meets the condition of the target even
				// number
				if i == j || j == k || i == k {
					continue
				}
				num := digits[i]*100 + digits[j]*10 + digits[k]
				if num >= 100 && num%2 == 0 {
					nums[num] = true
				}
			}
		}
	}
	// Converted to an array sorted in ascending order
	res := make([]int, 0, len(nums))
	for num := range nums {
		res = append(res, num)
	}
	sort.Ints(res)
	return res
}
