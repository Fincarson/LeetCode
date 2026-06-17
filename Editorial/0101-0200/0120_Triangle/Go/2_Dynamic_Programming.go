func minimumTotal(triangle [][]int) int {
    prevRow := make([]int, len(triangle[0]))
    copy(prevRow, triangle[0])
    for row := 1; row < len(triangle); row++ {
        currRow := make([]int, row+1)
        for col := 0; col <= row; col++ {
            smallestAbove := int(^uint(0) >> 1)
            if col > 0 {
                smallestAbove = prevRow[col-1]
            }
            if col < row {
                smallestAbove = min(smallestAbove, prevRow[col])
            }
            currRow[col] = smallestAbove + triangle[row][col]
        }
        prevRow = currRow
    }
    min_val := prevRow[0]
    for i := 0; i < len(prevRow); i++ {
        min_val = min(min_val, prevRow[i])
    }
    return min_val
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
