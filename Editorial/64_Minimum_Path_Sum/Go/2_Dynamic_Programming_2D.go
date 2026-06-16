func minPathSum(grid [][]int) int {
    m := len(grid)
    n := len(grid[0])
    dp := make([][]int, m)
    for i := range dp {
        dp[i] = make([]int, n)
    }
    for i := m - 1; i >= 0; i-- {
        for j := n - 1; j >= 0; j-- {
            if i == m-1 && j != n-1 {
                dp[i][j] = grid[i][j] + dp[i][j+1]
            } else if j == n-1 && i != m-1 {
                dp[i][j] = grid[i][j] + dp[i+1][j]
            } else if j != n-1 && i != m-1 {
                dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1])
            } else {
                dp[i][j] = grid[i][j]
            }
        }
    }
    return dp[0][0]
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
