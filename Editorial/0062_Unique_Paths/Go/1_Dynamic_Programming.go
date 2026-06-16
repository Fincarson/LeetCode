func uniquePaths(m int, n int) int {
    d := make([][]int, m)
    for i := range d {
        d[i] = make([]int, n)
        for j := range d[i] {
            d[i][j] = 1
        }
    }
    for col := 1; col < m; col++ {
        for row := 1; row < n; row++ {
            d[col][row] = d[col-1][row] + d[col][row-1]
        }
    }
    return d[m-1][n-1]
}
