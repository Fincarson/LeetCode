func minCut(s string) int {
    return findMinimumCut(s, 0, len(s)-1, len(s)-1)
}

func findMinimumCut(s string, start int, end int, minimumCut int) int {
    // base condition, no cut needed for an empty substring or palindrome substring.
    if start == end || isPalindrome(s, start, end) {
        return 0
    }
    for currentEndIndex := start; currentEndIndex <= end; currentEndIndex++ {
        // find result for substring (start, currentEndIndex) if it is palindrome
        if isPalindrome(s, start, currentEndIndex) {
            minimumCut = min(
                minimumCut,
                1+findMinimumCut(s, currentEndIndex+1, end, minimumCut),
            )
        }
    }
    return minimumCut
}

func isPalindrome(s string, start int, end int) bool {
    for start < end {
        if s[start] != s[end] {
            return false
        }
        start++
        end--
    }
    return true
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
