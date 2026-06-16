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
    
    l, r, ans := 1, min(m, n), 0
    for l <= r {
        mid := (l + r) / 2
        find := false
        for i := 1; i <= m-mid+1; i++ {
            for j := 1; j <= n-mid+1; j++ {
                sum := P[i+mid-1][j+mid-1] - P[i-1][j+mid-1] - P[i+mid-1][j-1] + P[i-1][j-1]
                if sum <= threshold {
                    find = true
                    break
                }
            }
            if find {
                break
            }
        }
        if find {
            ans = mid
            l = mid + 1
        } else {
            r = mid - 1
        }
    }
    return ans
}
