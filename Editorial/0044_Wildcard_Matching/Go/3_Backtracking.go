func isMatch(s string, p string) bool {
    sLen, pLen := len(s), len(p)
    sIdx, pIdx, starIdx, sTmpIdx := 0, 0, -1, -1
    for sIdx < sLen {
        if pIdx < pLen && (p[pIdx] == '?' || p[pIdx] == s[sIdx]) {
            sIdx++
            pIdx++
        } else if pIdx < pLen && p[pIdx] == '*' {
            starIdx = pIdx
            sTmpIdx = sIdx
            pIdx++
        } else if starIdx == -1 {
            return false
        } else {
            pIdx = starIdx + 1
            sIdx = sTmpIdx + 1
            sTmpIdx = sIdx
        }
    }
    for i := pIdx; i < pLen; i++ {
        if p[i] != '*' {
            return false
        }
    }
    return true
}
