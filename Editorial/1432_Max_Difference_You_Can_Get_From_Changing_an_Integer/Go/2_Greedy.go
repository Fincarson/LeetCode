func maxDiff(num int) int {
	// Replace characters in the string.
	replace := func(s string, x, y byte) string {
		return strings.ReplaceAll(s, string(x), string(y))
	}
	minNum := strconv.Itoa(num)
	maxNum := strconv.Itoa(num)
	// Find a high position and replace it with 9.
	for _, digit := range maxNum {
		if digit != '9' {
			maxNum = replace(maxNum, byte(digit), '9')
			break
		}
	}
	// Replace the most significant bit with 1
	// Or find a high-order digit that is not equal to the highest digit and
	// replace it with 0.
	for i := 0; i < len(minNum); i++ {
		digit := minNum[i]
		if i == 0 {
			if digit != '1' {
				minNum = replace(minNum, digit, '1')
				break
			}
		} else {
			if digit != '0' && digit != minNum[0] {
				minNum = replace(minNum, digit, '0')
				break
			}
		}
	}

	max, _ := strconv.Atoi(maxNum)
	min, _ := strconv.Atoi(minNum)
	return max - min
}
