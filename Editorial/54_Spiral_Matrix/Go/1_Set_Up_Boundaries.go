func spiralOrder(matrix [][]int) []int {
    var result []int
    rows := len(matrix)
    columns := len(matrix[0])
    up := 0
    left := 0
    right := columns - 1
    down := rows - 1
    for len(result) < rows*columns {
        // Traverse from left to right.
        for col := left; col <= right; col++ {
            result = append(result, matrix[up][col])
        }
        // Traverse downwards.
        for row := up + 1; row <= down; row++ {
            result = append(result, matrix[row][right])
        }
        // Make sure we are now on a different row.
        if up != down {
            // Traverse from right to left.
            for col := right - 1; col >= left; col-- {
                result = append(result, matrix[down][col])
            }
        }
        // Make sure we are now on a different column.
        if left != right {
            // Traverse upwards.
            for row := down - 1; row > up; row-- {
                result = append(result, matrix[row][left])
            }
        }
        left++
        right--
        up++
        down--
    }
    return result
}
