func minimumTotal(triangle [][]int) int {
    for row := 1; row < len(triangle); row++ {
        for col := 0; col <= row; col++ {
            smallestAbove := math.MaxInt32
            if col > 0 {
                smallestAbove = triangle[row-1][col-1]
            }
            if col < row {
                smallestAbove = min(smallestAbove, triangle[row-1][col])
            }
            triangle[row][col] += smallestAbove
        }
    }
    return minSlice(triangle[len(triangle)-1])
}

func minSlice(slice []int) int {
    minVal := slice[0]
    for _, val := range slice {
        minVal = min(minVal, val)
    }
    return minVal
}

func min(a int, b int) int {
    if a < b {
        return a
    }
    return b
}
