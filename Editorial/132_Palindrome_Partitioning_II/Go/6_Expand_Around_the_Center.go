func minCut(s string) int {
    cutsDp := make([]int, len(s))
    for i := 1; i < len(s); i++ {
        cutsDp[i] = i
    }
    for mid := 0; mid < len(s); mid++ {
        findMinimumCuts(mid, mid, cutsDp, s)
        findMinimumCuts(mid-1, mid, cutsDp, s)
    }
    return cutsDp[len(s)-1]
}

func findMinimumCuts(startIndex, endIndex int, cutsDp []int, s string) {
    for start, end := startIndex, endIndex; start >= 0 && end < len(s) && s[start] == s[end]; start, end = start-1, end+1 {
        var newCut int
        if start == 0 {
            newCut = 0
        } else {
            newCut = cutsDp[start-1] + 1
        }
        if cutsDp[end] > newCut {
            cutsDp[end] = newCut
        }
    }
}
