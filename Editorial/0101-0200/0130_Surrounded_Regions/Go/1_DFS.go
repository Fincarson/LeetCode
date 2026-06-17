func solve(board [][]byte) {
    if board == nil || len(board) == 0 {
        return
    }
    ROWS := len(board)
    COLS := len(board[0])
    borders := [][]int{}
    for r := 0; r < ROWS; r++ {
        borders = append(borders, []int{r, 0})
        borders = append(borders, []int{r, COLS - 1})
    }
    for c := 0; c < COLS; c++ {
        borders = append(borders, []int{0, c})
        borders = append(borders, []int{ROWS - 1, c})
    }
    var DFS func([][]byte, int, int)
    DFS = func(board [][]byte, row int, col int) {
        if board[row][col] != 'O' {
            return
        }
        board[row][col] = 'E'
        if col < COLS-1 {
            DFS(board, row, col+1)
        }
        if row < ROWS-1 {
            DFS(board, row+1, col)
        }
        if col > 0 {
            DFS(board, row, col-1)
        }
        if row > 0 {
            DFS(board, row-1, col)
        }
    }
    for _, pair := range borders {
        DFS(board, pair[0], pair[1])
    }
    for r := 0; r < ROWS; r++ {
        for c := 0; c < COLS; c++ {
            if board[r][c] == 'O' {
                board[r][c] = 'X'
            }
            if board[r][c] == 'E' {
                board[r][c] = 'O'
            }
        }
    }
}
