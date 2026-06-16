func canPartitionGrid(grid [][]int) bool {
    m, n := len(grid), len(grid[0])
    sum := make([][]int64, m+1)
    for i := range sum {
        sum[i] = make([]int64, n+1)
    }
    var total int64 = 0
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + int64(grid[i][j])
            total += int64(grid[i][j])
        }
    }
    for i := 0; i < m-1; i++ {
        if total == sum[i+1][n]*2 {
            return true
        }
    }
    for i := 0; i < n-1; i++ {
        if total == sum[m][i+1]*2 {
            return true
        }
    }
    return false
}
