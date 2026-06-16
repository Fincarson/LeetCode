func canBeTypedWords(text string, brokenLetters string) int {
	broken := make(map[rune]bool) // set of broken letter keys
	for _, ch := range brokenLetters {
		broken[ch] = true
	}
	res := 0     // the number of words that can be fully inputted
	flag := true // is the current character in the word completely inputtable
	for _, ch := range text {
		if ch == ' ' {
			// the current character is a space, check the status of the
			// previous word, update the count and initialize the flag
			if flag {
				res++
			}
			flag = true
		} else if broken[ch] {
			// the current character cannot be entered, the word it is in cannot
			// be fully entered, update flag
			flag = false
		}
	}
	// judge the status of the last word and update the count
	if flag {
		res++
	}
	return res
}
