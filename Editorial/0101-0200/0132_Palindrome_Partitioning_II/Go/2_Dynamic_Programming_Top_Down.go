var (
    memoCuts       [][]int
    memoPalindrome [][]*bool
)

func minCut(s string) int {
    memoCuts = make([][]int, len(s))
    memoPalindrome = make([][]*bool, len(s))
    for i := range memoCuts {
        memoCuts[i] = make([]int, len(s))
        for j := range memoCuts[i] {
            memoCuts[i][j] = -1
        }
    }
    for i := range memoPalindrome {
        memoPalindrome[i] = make([]*bool, len(s))
    }
    return findMinimumCut(s, 0, len(s)-1, len(s)-1)
}

func findMinimumCut(s string, start, end, minimumCut int) int {
    if start == end || isPalindrome(s, start, end) {
        return 0
    }
    if memoCuts[start][end] != -1 {
        return memoCuts[start][end]
    }
    for currentEndIndex := start; currentEndIndex <= end; currentEndIndex++ {
        if isPalindrome(s, start, currentEndIndex) {
            minCut := findMinimumCut(s, currentEndIndex+1, end, minimumCut)
            if minCut+1 < minimumCut {
                minimumCut = minCut + 1
            }
        }
    }
    memoCuts[start][end] = minimumCut
    return minimumCut
}

func isPalindrome(s string, start, end int) bool {
    if start >= end {
        return true
    }
    if memoPalindrome[start][end] != nil {
        return *memoPalindrome[start][end]
    }
    palindrome := s[start] == s[end] && isPalindrome(s, start+1, end-1)
    memoPalindrome[start][end] = &palindrome
    return palindrome
}
