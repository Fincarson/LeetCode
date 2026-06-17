func strStr(haystack string, needle string) int {
    m := len(needle)
    n := len(haystack)

    for windowStart := 0; windowStart <= n-m; windowStart++ {
        for i := 0; i < m; i++ {
            if needle[i] != haystack[windowStart+i] {
                break
            }
            if i == m-1 {
                return windowStart
            }
        }
    }

    return -1
}
