func maximumProfit(prices []int, k int) int64 {
    n := len(prices)
    dp := make([][][]int64, n)
    for i := range dp {
        dp[i] = make([][]int64, k + 1)
        for j := range dp[i] {
            dp[i][j] = make([]int64, 3)
        }
    }
    
    // initialize the state on day 0
    for j := 1; j <= k; j++ {
        dp[0][j][1] = int64(-prices[0])
        dp[0][j][2] = int64(prices[0])
    }
    
    for i := 1; i < n; i++ {
        for j := 1; j <= k; j++ {
            dp[i][j][0] = max(dp[i - 1][j][0], max(dp[i-1][j][1] + int64(prices[i]), dp[i - 1][j][2] - int64(prices[i])))
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - int64(prices[i]))
            dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][0] + int64(prices[i]))
        }
    }
    
    return dp[n - 1][k][0]
}
