func lengthOfLongestSubstring(s string) int {
	charToNextIndex := make(map[byte]int)
	maxLen := 0
	left := 0
	for right := 0; right < len(s); right++ {
		if prev, ok := charToNextIndex[s[right]]; ok {
			left = max(left, prev)
		}
		maxLen = max(maxLen, right-left+1)
		charToNextIndex[s[right]] = right + 1
	}
	return maxLen
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
