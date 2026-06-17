func reverseWords(s string) string {
    s = strings.TrimSpace(
        s,
    ) // Trim is done in the beginning to simplify the code
    words := strings.Fields(s)
    left := 0
    right := len(words) - 1
    for left < right {
        words[left], words[right] = words[right], words[left]
        left++
        right--
    }
    return strings.Join(words, " ")
}
