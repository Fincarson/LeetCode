func maxDiff(num int) int {
	// Define a function "change", to replace x with y in a number.
	change := func(x, y int) string {
		numStr := strconv.Itoa(num)
		var res strings.Builder
		for _, digit := range numStr {
			if int(digit-'0') == x {
				res.WriteByte(byte('0' + y))
			} else {
				res.WriteRune(digit)
			}
		}
		return res.String()
	}

	minNum := num
	maxNum := num
	// Traverse all possible replacement combinations
	for x := 0; x < 10; x++ {
		for y := 0; y < 10; y++ {
			res := change(x, y)
			// Check if there are leading zeros
			if res[0] != '0' {
				res_i, _ := strconv.Atoi(res)
				minNum = min(minNum, res_i)
				maxNum = max(maxNum, res_i)
			}
		}
	}

	return maxNum - minNum
}
