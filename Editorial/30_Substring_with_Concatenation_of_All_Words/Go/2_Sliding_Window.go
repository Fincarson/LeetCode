// To be precise, Go’s map is like a mix of dictionary and hash table in Python, even though Go's documentation called it a "Hash Table".
// Mutating a map or reading from it is not thread-safe.
// Like the usage in C, Go and C support threads to operate the map themselves, while using the concurrent map thread-safely.
func slidingWindow(left int, s string, wordCount map[string]int,
    k int, wordLength int, substringSize int, n int, result []int,
) []int {
    wordsFound := make(map[string]int)
    wordsUsed := 0
    excessWord := false
    for right := left; right <= n-wordLength; right += wordLength {
        sub := s[right : right+wordLength]
        _, ok := wordCount[sub]
        if !ok {
            wordsFound = make(map[string]int)
            wordsUsed = 0
            excessWord = false
            left = right + wordLength
        } else {
            for right-left == substringSize || excessWord {
                leftmostWord := s[left : left+wordLength]
                left += wordLength
                wordsFound[leftmostWord]--
                // map[key] - retrieve value; if key does not exist, you get zero value for the type of the items e.g., 0 for int, "" for string, nil for any type of pointers, functions, interfaces, slices, channels.
                if wordsFound[leftmostWord] >= wordCount[leftmostWord] {
                    excessWord = false
                } else {
                    wordsUsed--
                }
            }
            wordsFound[sub]++
            if wordsFound[sub] <= wordCount[sub] {
                wordsUsed++
            } else {
                excessWord = true
            }
            if wordsUsed == k && !excessWord {
                result = append(result, left)
            }
        }
    }
    return result
}

func findSubstring(s string, words []string) []int {
    wordCount := make(map[string]int)
    for _, word := range words {
        wordCount[word]++
    }
    wordLength := len(words[0])
    k := len(words)
    n := len(s)
    substringSize := wordLength * k
    result := make([]int, 0)
    for i := 0; i < wordLength; i++ {
        result = slidingWindow(
            i,
            s,
            wordCount,
            k,
            wordLength,
            substringSize,
            n,
            result,
        )
    }
    return result
}
