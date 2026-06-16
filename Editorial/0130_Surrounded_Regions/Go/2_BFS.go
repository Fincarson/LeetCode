type pair struct {
    first  int
    second int
}

func solve(board [][]byte) {
    if len(board) == 0 || len(board[0]) == 0 {
        return
    }
    ROWS := len(board)
    COLS := len(board[0])
    border := make([]pair, 0)
    for r := 0; r < ROWS; r++ {
        border = append(border, pair{r, 0})
        border = append(border, pair{r, COLS - 1})
    }
    for c := 0; c < COLS; c++ {
        border = append(border, pair{0, c})
        border = append(border, pair{ROWS - 1, c})
    }
    for _, pair := range border {
        BFS(board, pair.first, pair.second, ROWS, COLS)
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

func BFS(board [][]byte, row int, col int, ROWS int, COLS int) {
    queue := make([]pair, 0)
    queue = append(queue, pair{row, col})
    for len(queue) != 0 {
        top := queue[0]
        queue = queue[1:]
        row = top.first
        col = top.second
        if board[row][col] != 'O' {
            continue
        }
        board[row][col] = 'E'
        if col < COLS-1 {
            queue = append(queue, pair{row, col + 1})
        }
        if row < ROWS-1 {
            queue = append(queue, pair{row + 1, col})
        }
        if col > 0 {
            queue = append(queue, pair{row, col - 1})
        }
        if row > 0 {
            queue = append(queue, pair{row - 1, col})
        }
    }
}
