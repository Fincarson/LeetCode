func maximalRectangle(matrix [][]byte) int {
    if len(matrix) == 0 {
        return 0
    }
    m := len(matrix)
    n := len(matrix[0])
    left := make([]int, n)
    right := make([]int, n)
    height := make([]int, n)
    for i := range right {
        right[i] = n
    }
    maxarea := 0
    for i := 0; i < m; i++ {
        cur_left := 0
        cur_right := n
        for j := 0; j < n; j++ {
            if matrix[i][j] == '1' {
                height[j]++
            } else {
                height[j] = 0
            }
        }
        for j := 0; j < n; j++ {
            if matrix[i][j] == '1' {
                left[j] = max(left[j], cur_left)
            } else {
                left[j] = 0
                cur_left = j + 1
            }
        }
        for j := n - 1; j >= 0; j-- {
            if matrix[i][j] == '1' {
                right[j] = min(right[j], cur_right)
            } else {
                right[j] = n
                cur_right = j
            }
        }
        for j := 0; j < n; j++ {
            maxarea = max(maxarea, (right[j]-left[j])*height[j])
        }
    }
    return maxarea
}
