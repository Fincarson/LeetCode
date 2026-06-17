func isMatch(s string, p string) bool {
    dp := make(map[string]bool)
    remove_duplicate_stars := func(p string) string {
        new_string := ""
        for _, c := range p {
            if len(new_string) == 0 || c != '*' {
                new_string += string(c)
            } else if new_string[len(new_string)-1] != '*' {
                new_string += string(c)
            }
        }
        return new_string
    }
    var helper func(int, int) bool
    helper = func(si int, pi int) bool {
        key := fmt.Sprintf("%d,%d", si, pi)
        if _, ok := dp[key]; ok {
            return dp[key]
        }
        if pi == len(p) {
            dp[key] = si == len(s)
        } else if si == len(s) {
            dp[key] = pi+1 == len(p) && p[pi] == '*'
        } else if p[pi] == s[si] || p[pi] == '?' {
            dp[key] = helper(si+1, pi+1)
        } else if p[pi] == '*' {
            dp[key] = helper(si, pi+1) || helper(si+1, pi)
        } else {
            dp[key] = false
        }
        return dp[key]
    }
    p = remove_duplicate_stars(p)
    return helper(0, 0)
}
