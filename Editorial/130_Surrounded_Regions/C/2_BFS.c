void solve(char** board, int boardSize, int* boardColSize) {
    if (!board || !board[0]) {
        return;
    }
    const int ROWS = boardSize;
    const int COLS = boardColSize[0];
    for (int r = 0; r < ROWS; ++r) {
        BFS(board, ROWS, COLS, r, 0);
        BFS(board, ROWS, COLS, r, COLS - 1);
    }
    for (int c = 0; c < COLS; ++c) {
        BFS(board, ROWS, COLS, 0, c);
        BFS(board, ROWS, COLS, ROWS - 1, c);
    }
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            if (board[r][c] == 'O') board[r][c] = 'X';
            if (board[r][c] == 'E') board[r][c] = 'O';
        }
    }
}
void BFS(char** board, int ROWS, int COLS, int row, int col) {
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS ||
        board[row][col] != 'O')
        return;
    board[row][col] = 'E';
    BFS(board, ROWS, COLS, row + 1, col);
    BFS(board, ROWS, COLS, row - 1, col);
    BFS(board, ROWS, COLS, row, col + 1);
    BFS(board, ROWS, COLS, row, col - 1);
}
