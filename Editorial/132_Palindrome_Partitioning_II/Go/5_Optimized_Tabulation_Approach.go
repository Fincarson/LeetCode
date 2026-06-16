func minCut(s string) int {
    length := len(s)
    cuts := make([]int, length)
    palindrome := make([][]bool, length)
    for i := 0; i < length; i++ {
        palindrome[i] = make([]bool, length)
    }
    for end := 0; end < length; end++ {
        minimumCut := end
        for start := 0; start <= end; start++ {
            // check if substring (start, end) is palindrome
            if s[start] == s[end] &&
                (end-start <= 2 || palindrome[start+1][end-1]) {
                palindrome[start][end] = true
                if start == 0 {
                    minimumCut = 0
                } else {
                    minimumCut = min(minimumCut, cuts[start-1]+1)
                }
            }
        }
        cuts[end] = minimumCut
    }
    return cuts[length-1]
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
