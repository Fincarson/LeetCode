func totalNQueens(n int) int {
    size := n
    var backtrack func(int, map[int]bool, map[int]bool, map[int]bool) int
    backtrack = func(row int, diagonals, antiDiagonal, cols map[int]bool) int {
        if row == size {
            return 1
        }
        solutions := 0
        for col := 0; col < size; col++ {
            currDiagonal := row - col
            currAntiDiagonal := row + col
            // If the queen is not placeable
            if cols[col] || diagonals[currDiagonal] ||
                antiDiagonal[currAntiDiagonal] {
                continue
            }
            cols[col] = true
            diagonals[currDiagonal] = true
            antiDiagonal[currAntiDiagonal] = true
            // Move on to the next row with the updated board state
            solutions += backtrack(row+1, diagonals, antiDiagonal, cols)
            delete(cols, col)
            delete(diagonals, currDiagonal)
            delete(antiDiagonal, currAntiDiagonal)
        }
        return solutions
    }
    return backtrack(
        0,
        make(map[int]bool),
        make(map[int]bool),
        make(map[int]bool),
    )
}
