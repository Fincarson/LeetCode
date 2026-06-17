func lengthOfLastWord(s string) int {
    count := 0
    lastIndex := len(s) - 1
    // Discard the trailing spaces
    for lastIndex >= 0 && s[lastIndex] == ' ' {
        lastIndex--
    }
    // Iterate through the last word
    for lastIndex >= 0 && s[lastIndex] != ' ' {
        count++
        lastIndex--
    }
    return count
}
