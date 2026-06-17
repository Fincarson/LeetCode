func isValidSudoku(board [][]byte) bool {
    N := 9
    // Use hash set to record the status
    rows := make([]map[byte]bool, N)
    cols := make([]map[byte]bool, N)
    boxes := make([]map[byte]bool, N)
    for i := 0; i < N; i++ {
        rows[i] = make(map[byte]bool)
        cols[i] = make(map[byte]bool)
        boxes[i] = make(map[byte]bool)
    }
    for r := 0; r < N; r++ {
        for c := 0; c < N; c++ {
            val := board[r][c]
            // Check if the position is filled with number
            if val == '.' {
                continue
            }
            // Check the row
            if rows[r][val] {
                return false
            }
            rows[r][val] = true
            // Check the column
            if cols[c][val] {
                return false
            }
            cols[c][val] = true
            // Check the box
            idx := (r/3)*3 + c/3
            if boxes[idx][val] {
                return false
            }
            boxes[idx][val] = true
        }
    }
    return true
}
