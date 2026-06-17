func findEvenNumbers(digits []int) []int {
	res := []int{}
	freq := make(map[int]int)
	// Count the number of occurrences of each number in the integer array
	for _, d := range digits {
		freq[d]++
	}
	// Enumerate all three-digit even numbers
	for i := 100; i < 1000; i += 2 {
		freq1 := make(map[int]int)
		num := i
		// Count the frequency of each digit of the current even number
		for num > 0 {
			d := num % 10
			freq1[d]++
			num /= 10
		}
		// Check if the conditions are met
		isValid := true
		for d, count := range freq1 {
			if freq[d] < count {
				isValid = false
				break
			}
		}
		if isValid {
			res = append(res, i)
		}
	}
	return res
}
