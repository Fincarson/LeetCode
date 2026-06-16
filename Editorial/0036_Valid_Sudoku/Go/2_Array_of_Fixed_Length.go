func isValidSudoku(board [][]byte) bool {
    var N int = 9
    var rows [9][9]int
    var cols [9][9]int
    var boxes [9][9]int
    for r := 0; r < N; r++ {
        for c := 0; c < N; c++ {
            if board[r][c] == '.' {
                continue
            }
            pos := int(board[r][c] - '1')
            if rows[r][pos] == 1 {
                return false
            }
            rows[r][pos] = 1
            if cols[c][pos] == 1 {
                return false
            }
            cols[c][pos] = 1
            idx := (r/3)*3 + c/3
            if boxes[idx][pos] == 1 {
                return false
            }
            boxes[idx][pos] = 1
        }
    }
    return true
}
