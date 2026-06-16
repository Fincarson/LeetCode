func isValidSudoku(board [][]byte) bool {
    N := 9
    // Use binary number to check previous occurrence
    var rows [9]int
    var cols [9]int
    var boxes [9]int
    for r := 0; r < N; r++ {
        for c := 0; c < N; c++ {
            // Check if the position is filled with number
            if board[r][c] == '.' {
                continue
            }
            val := int(board[r][c] - '0')
            pos := 1 << (val - 1)
            // Check the row
            if rows[r]&pos != 0 {
                return false
            }
            rows[r] |= pos
            // Check the column
            if cols[c]&pos != 0 {
                return false
            }
            cols[c] |= pos
            // Check the box
            idx := (r/3)*3 + c/3
            if boxes[idx]&pos != 0 {
                return false
            }
            boxes[idx] |= pos
        }
    }
    return true
}
