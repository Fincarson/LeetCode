func reverseWords(s string) string {
    // split by spaces
    words := strings.Fields(s)
    // reverse
    for i := 0; i < len(words)/2; i++ {
        words[i], words[len(words)-i-1] = words[len(words)-i-1], words[i]
    }
    // join the words with a space
    return strings.Join(words, " ")
}
