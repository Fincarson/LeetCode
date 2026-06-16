func isPalindrome(s string) bool {
    filteredChars := ""
    for _, ch := range s {
        if unicode.IsLetter(ch) || unicode.IsNumber(ch) {
            filteredChars += strings.ToLower(string(ch))
        }
    }
    reversedChars := reverseString(filteredChars)
    return filteredChars == reversedChars
}

func reverseString(s string) string {
    chars := []rune(s)
    for i, j := 0, len(chars)-1; i < j; i, j = i+1, j-1 {
        chars[i], chars[j] = chars[j], chars[i]
    }
    return string(chars)
}
