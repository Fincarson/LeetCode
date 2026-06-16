bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int N = 9;
    int rows[N][N];
    memset(rows, 0, sizeof(rows));
    int cols[N][N];
    memset(cols, 0, sizeof(cols));
    int boxes[N][N];
    memset(boxes, 0, sizeof(boxes));
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (board[r][c] == '.') {
                continue;
            }
            int pos = board[r][c] - '1';
            if (rows[r][pos] == 1) {
                return false;
            }
            rows[r][pos] = 1;
            if (cols[c][pos] == 1) {
                return false;
            }
            cols[c][pos] = 1;
            int idx = (r / 3) * 3 + c / 3;
            if (boxes[idx][pos] == 1) {
                return false;
            }
            boxes[idx][pos] = 1;
        }
    }
    return true;
}
