func minCut(s string) int {
    memoCuts := make([]int, len(s))
    for i := range memoCuts {
        memoCuts[i] = -1
    }
    memoPalindrome := make([][]bool, len(s))
    for i := range memoPalindrome {
        memoPalindrome[i] = make([]bool, len(s))
    }
    var findMinimumCut func(string, int, int, int) int
    var isPalindrome func(string, int, int) bool
    var min func(int, int) int
    findMinimumCut = func(s string, start int, end int, minimumCut int) int {
        // base case
        if start == end || isPalindrome(s, start, end) {
            return 0
        }
        // check for results in memoCuts
        if memoCuts[start] != -1 {
            return memoCuts[start]
        }
        for currentEndIndex := start; currentEndIndex <= end; currentEndIndex++ {
            if isPalindrome(s, start, currentEndIndex) {
                minimumCut = min(
                    minimumCut,
                    1+findMinimumCut(s, currentEndIndex+1, end, minimumCut),
                )
            }
        }
        memoCuts[start] = minimumCut
        return minimumCut
    }
    isPalindrome = func(s string, start int, end int) bool {
        if start >= end {
            return true
        }
        // check for results in memoPalindrome
        if memoPalindrome[start][end] != false {
            return memoPalindrome[start][end]
        }
        memoPalindrome[start][end] = (s[start] == s[end]) &&
            isPalindrome(s, start+1, end-1)
        return memoPalindrome[start][end]
    }
    min = func(x, y int) int {
        if x < y {
            return x
        }
        return y
    }
    return findMinimumCut(s, 0, len(s)-1, len(s)-1)
}
