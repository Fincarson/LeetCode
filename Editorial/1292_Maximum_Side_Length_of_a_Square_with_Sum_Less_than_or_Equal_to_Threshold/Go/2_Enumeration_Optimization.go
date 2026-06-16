func maxSideLength(mat [][]int, threshold int) int {
    m, n := len(mat), len(mat[0])
    P := make([][]int, m+1)
    for i := range P {
        P[i] = make([]int, n+1)
    }
    
    for i := 1; i <= m; i++ {
        for j := 1; j <= n; j++ {
            P[i][j] = P[i-1][j] + P[i][j-1] - P[i-1][j-1] + mat[i-1][j-1]
        }
    }
    
    getRect := func(x1, y1, x2, y2 int) int {
        return P[x2][y2] - P[x1-1][y2] - P[x2][y1-1] + P[x1-1][y1-1]
    }
    
    r := min(m, n)
    ans := 0
    for i := 1; i <= m; i++ {
        for j := 1; j <= n; j++ {
            for c := ans + 1; c <= r; c++ {
                if i+c-1 <= m && j+c-1 <= n && getRect(i, j, i+c-1, j+c-1) <= threshold {
                    ans = c
                } else {
                    break
                }
            }
        }
    }
    return ans
}
