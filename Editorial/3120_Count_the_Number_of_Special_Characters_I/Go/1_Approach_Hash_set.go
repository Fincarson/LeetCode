func numberOfSpecialChars(word string) int {
	s := make(map[rune]bool)
	for _, c := range word {
		s[c] = true
	}
	ans := 0
	for c := 'a'; c <= 'z'; c++ {
		if s[c] && s[c-'a'+'A'] {
			ans++
		}
	}
	return ans
}
