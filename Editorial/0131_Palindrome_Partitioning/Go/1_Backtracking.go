func partition(s string) [][]string {
    res := [][]string{}
    dfs(s, []string{}, &res)
    return res
}

func dfs(s string, path []string, res *[][]string) {
    if len(s) == 0 {
        *res = append(*res, append([]string(nil), path...))
        return
    }
    for i := 1; i <= len(s); i++ {
        if isPalindrome(s[:i]) {
            dfs(s[i:], append(path, s[:i]), res)
        }
    }
}

func isPalindrome(s string) bool {
    lo, hi := 0, len(s)-1
    for lo < hi {
        if s[lo] != s[hi] {
            return false
        }
        lo++
        hi--
    }
    return true
}
