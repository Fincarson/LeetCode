func longestPalindrome(s string) string {
    n := len(s)
    dp := make([][]bool, n)
    for i := range dp {
        dp[i] = make([]bool, n)
    }
    ans := []int{0, 0}

    for i := 0; i < n; i++ {
        dp[i][i] = true
    }

    for i := 0; i < n-1; i++ {
        if s[i] == s[i+1] {
            dp[i][i+1] = true
            ans = []int{i, i + 1}
        }
    }

    for diff := 2; diff < n; diff++ {
        for i := 0; i < n-diff; i++ {
            j := i + diff
            if s[i] == s[j] && dp[i+1][j-1] {
                dp[i][j] = true
                ans = []int{i, j}
            }
        }
    }
    i, j := ans[0], ans[1]
    return s[i : j+1]
}
