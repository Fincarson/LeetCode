func setZeroes(matrix [][]int) {
    rows := make(map[int]bool)
    cols := make(map[int]bool)
    // Essentially, we mark the rows and columns that are to be made zero
    for i := 0; i < len(matrix); i++ {
        for j := 0; j < len(matrix[0]); j++ {
            if matrix[i][j] == 0 {
                rows[i] = true
                cols[j] = true
            }
        }
    }
    // Iterate over the array once again and using the rows and cols sets, update the elements
    for i := 0; i < len(matrix); i++ {
        for j := 0; j < len(matrix[0]); j++ {
            if rows[i] || cols[j] {
                matrix[i][j] = 0
            }
        }
    }
}
