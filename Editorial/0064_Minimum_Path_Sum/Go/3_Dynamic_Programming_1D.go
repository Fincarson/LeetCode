func minPathSum(grid [][]int) int {
    dp := make([]int, len(grid[0]))
    for i := len(grid) - 1; i >= 0; i-- {
        for j := len(grid[0]) - 1; j >= 0; j-- {
            if i == len(grid)-1 && j != len(grid[0])-1 {
                dp[j] = grid[i][j] + dp[j+1]
            } else if j == len(grid[0])-1 && i != len(grid)-1 {
                dp[j] = grid[i][j] + dp[j]
            } else if i != len(grid)-1 && j != len(grid[0])-1 {
                dp[j] = grid[i][j] + min(dp[j], dp[j+1])
            } else {
                dp[j] = grid[i][j]
            }
        }
    }
    return dp[0]
}

func min(a int, b int) int {
    if a < b {
        return a
    }
    return b
}
