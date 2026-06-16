func longestCommonPrefix(strs []string) string {
    if strs == nil || len(strs) < 1 {
        return ""
    }

    var LCP func(string, string) string
    LCP = func(str1, str2 string) string {
        minLen := min(len(str1), len(str2))
        for i := 0; i < minLen; i++ {
            if str1[i] != str2[i] {
                return str1[0:i]
            }
        }
        return str1[0:minLen]
    }

    var divideAndConquer func([]string, int, int) string
    divideAndConquer = func(strs []string, l, r int) string {
        if l == r {
            return strs[l]
        } else {
            mid := (l + r) / 2
            lcpLeft := divideAndConquer(strs, l, mid)
            lcpRight := divideAndConquer(strs, mid+1, r)
            return LCP(lcpLeft, lcpRight)
        }
    }

    return divideAndConquer(strs, 0, len(strs)-1)
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
