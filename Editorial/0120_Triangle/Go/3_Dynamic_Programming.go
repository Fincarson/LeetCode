func minimumTotal(triangle [][]int) int {
    for row := len(triangle) - 2; row >= 0; row-- {
        for col := 0; col <= row; col++ {
            bestBelow := min(triangle[row+1][col], triangle[row+1][col+1])
            triangle[row][col] += bestBelow
        }
    }
    return triangle[0][0]
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
