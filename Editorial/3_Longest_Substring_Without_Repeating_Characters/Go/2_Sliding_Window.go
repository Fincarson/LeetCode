func lengthOfLongestSubstring(s string) int {
	chars := make(map[byte]int)

	left := 0
	right := 0

	res := 0
	for right < len(s) {
		r := s[right]
		chars[r]++

		for chars[r] > 1 {
			l := s[left]
			chars[l]--
			left++
		}

		res = max(res, right-left+1)
		right++
	}

	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
