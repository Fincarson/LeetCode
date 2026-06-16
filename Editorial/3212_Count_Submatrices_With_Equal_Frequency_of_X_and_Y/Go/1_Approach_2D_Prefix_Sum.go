func numberOfSubmatrices(grid [][]byte) int {
    n := len(grid)
    m := len(grid[0])
    ans := 0

    sum := make([][][]int, n+1)
    for i := range sum {
        sum[i] = make([][]int, m+1)
        for j := range sum[i] {
            sum[i][j] = make([]int, 2)
        }
    }

    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            if grid[i][j] == 'X' {
                sum[i+1][j+1][0] = sum[i+1][j][0] + sum[i][j+1][0] - sum[i][j][0] + 1
                sum[i+1][j+1][1] = 1
            } else if grid[i][j] == 'Y' {
                sum[i+1][j+1][0] = sum[i+1][j][0] + sum[i][j+1][0] - sum[i][j][0] - 1
                if sum[i+1][j][1] == 1 || sum[i][j+1][1] == 1 {
                    sum[i+1][j+1][1] = 1
                } else {
                    sum[i+1][j+1][1] = 0
                }
            } else {
                sum[i+1][j+1][0] = sum[i+1][j][0] + sum[i][j+1][0] - sum[i][j][0]
                if sum[i+1][j][1] == 1 || sum[i][j+1][1] == 1 {
                    sum[i+1][j+1][1] = 1
                } else {
                    sum[i+1][j+1][1] = 0
                }
            }

            if sum[i+1][j+1][0] == 0 && sum[i+1][j+1][1] == 1 {
                ans++
            }
        }
    }
    return ans
}
