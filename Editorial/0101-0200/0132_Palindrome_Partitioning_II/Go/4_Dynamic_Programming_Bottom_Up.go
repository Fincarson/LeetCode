func minCut(s string) int {
    cutsDp := make([]int, len(s))
    palindromeDp := make([][]bool, len(s))
    for i := range palindromeDp {
        palindromeDp[i] = make([]bool, len(s))
    }
    // build the palindrome cutsDp for all susbtrings
    buildPalindromeDp(s, len(s), palindromeDp)
    for end := 0; end < len(s); end++ {
        minimumCut := end
        for start := 0; start <= end; start++ {
            if palindromeDp[start][end] {
                if start == 0 {
                    minimumCut = 0
                } else {
                    minimumCut = Min(minimumCut, cutsDp[start-1]+1)
                }
            }
        }
        cutsDp[end] = minimumCut
    }
    return cutsDp[len(s)-1]
}

func buildPalindromeDp(s string, n int, palindromeDp [][]bool) {
    for end := 0; end < len(s); end++ {
        for start := 0; start <= end; start++ {
            if s[start] == s[end] &&
                (end-start <= 2 || palindromeDp[start+1][end-1]) {
                palindromeDp[start][end] = true
            }
        }
    }
}

func Min(x, y int) int {
    if x <= y {
        return x
    }
    return y
}
