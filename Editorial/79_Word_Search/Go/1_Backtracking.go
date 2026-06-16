func exist(board [][]byte, word string) bool {
    rows := len(board)
    if rows == 0 {
        return false
    }
    cols := len(board[0])

    var backtrack func(row int, col int, index int) bool
    backtrack = func(row int, col int, index int) bool {
        /* Step 1). check the bottom case. */
        if index == len(word) {
            return true
        }
        /* Step 2). Check the boundaries. */
        if row < 0 || row >= rows || col < 0 || col >= cols ||
            board[row][col] != word[index] {
            return false
        }

        /* Step 3). explore the neighbors in DFS */
        ret := false
        temp := board[row][col]
        // mark the path before the next exploration
        board[row][col] = '#'
        rowOffsets := []int{0, 1, 0, -1}
        colOffsets := []int{1, 0, -1, 0}

        for d := 0; d < 4; d++ {
            ret = backtrack(row+rowOffsets[d], col+colOffsets[d], index+1)
            if ret {
                break
            }
        }

        // Unmark the cell as visited
        board[row][col] = temp
        return ret
    }

    for row := 0; row < rows; row++ {
        for col := 0; col < cols; col++ {
            if board[row][col] == word[0] && backtrack(row, col, 0) {
                return true
            }
        }
    }
    return false
}
