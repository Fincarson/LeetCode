func maximalRectangle(matrix [][]byte) int {
    if len(matrix) == 0 {
        return 0
    }
    maxarea := 0
    dp := make([][]int, len(matrix))
    for i := range dp {
        dp[i] = make([]int, len(matrix[0]))
    }
    for i := 0; i < len(matrix); i++ {
        for j := 0; j < len(matrix[0]); j++ {
            if matrix[i][j] == '1' {
                // compute the maximum width and update dp with it
                dp[i][j] = 1
                if j != 0 {
                    dp[i][j] += dp[i][j-1]
                }
                width := dp[i][j]
                // compute the maximum area rectangle with a lower right corner at [i, j]
                for k := i; k >= 0; k-- {
                    width = min(width, dp[k][j])
                    maxarea = max(maxarea, width*(i-k+1))
                }
            }
        }
    }
    return maxarea
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}
