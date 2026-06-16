/* Golang */
func climbStairs(n int) int {
    q := [][]int{{1, 1}, {1, 0}}
    res := pow(q, n)
    return res[0][0]
}

func pow(a [][]int, n int) [][]int {
    ret := [][]int{{1, 0}, {0, 1}}
    for n > 0 {
        if (n & 1) == 1 {
            ret = multiply(ret, a)
        }
        n >>= 1
        a = multiply(a, a)
    }
    return ret
}

func multiply(a [][]int, b [][]int) [][]int {
    c := make([][]int, 2)
    for i := range c {
        c[i] = make([]int, 2)
    }
    for i := 0; i < 2; i++ {
        for j := 0; j < 2; j++ {
            c[i][j] = a[i][0]*b[0][j] + a[i][1]*b[1][j]
        }
    }
    return c
}
