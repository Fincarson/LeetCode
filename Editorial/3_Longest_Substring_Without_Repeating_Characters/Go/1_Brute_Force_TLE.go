func lengthOfLongestSubstring(s string) int {
	n := len(s)

	res := 0
	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			if checkRepetition(s, i, j) {
				if res < j-i+1 {
					res = j - i + 1
				}
			}
		}
	}

	return res
}

func checkRepetition(s string, start, end int) bool {
	chars := make(map[byte]bool)

	for i := start; i <= end; i++ {
		c := s[i]
		if _, ok := chars[c]; ok {
			return false
		}
		chars[c] = true
	}

	return true
}
