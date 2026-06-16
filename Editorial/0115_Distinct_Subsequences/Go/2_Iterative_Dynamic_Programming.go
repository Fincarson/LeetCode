// Golang
func numDistinct(s string, t string) int {
    M := len(s)
    N := len(t)
    // Dynamic Programming table
    dp := make([][]int, len(s)+1)
    for i := range dp {
        dp[i] = make([]int, len(t)+1)
    }
    // Base case initialization
    for j := 0; j <= N; j++ {
        dp[M][j] = 0
    }
    // Base case initialization
    for i := 0; i <= M; i++ {
        dp[i][N] = 1
    }
    // Iterate over the strings in reverse so as to
    // satisfy the way we've modeled our recursive solution
    for i := M - 1; i >= 0; i-- {
        for j := N - 1; j >= 0; j-- {
            // Remember, we always need this result
            dp[i][j] = dp[i+1][j]
            // If the characters match, we add the
            // result of the next recursion call (in this
            // case, the value of a cell in the dp table)
            if s[i] == t[j] {
                dp[i][j] += dp[i+1][j+1]
            }
        }
    }
    return dp[0][0]
}
