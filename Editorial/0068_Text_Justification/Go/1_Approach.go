func getWords(i int, words []string, maxWidth int) []string {
    currentLine := []string{}
    currLength := 0
    for i < len(words) && currLength+len(words[i]) <= maxWidth {
        currentLine = append(currentLine, words[i])
        currLength += len(words[i]) + 1
        i++
    }
    return currentLine
}
