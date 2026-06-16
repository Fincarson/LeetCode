func findSubstring(s string, words []string) []int {
    n := len(s)
    k := len(words)
    wordLength := len(words[0])
    substringSize := wordLength * k
    wordCount := make(map[string]int)
    for _, word := range words {
        wordCount[word]++
    }
    check := func(i int) bool {
        remaining := make(map[string]int)
        wordsUsed := 0
        for k := range wordCount {
            remaining[k] = wordCount[k]
        }
        for j := i; j < i+substringSize; j += wordLength {
            sub := s[j : j+wordLength]
            if remaining[sub] > 0 {
                remaining[sub]--
                wordsUsed++
            } else {
                break
            }
        }
        return wordsUsed == k
    }
    var answer []int
    for i := 0; i < n-substringSize+1; i++ {
        if check(i) {
            answer = append(answer, i)
        }
    }
    return answer
}
