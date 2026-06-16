bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int N = 9;
    // Use binary number to check previous occurrence
    unsigned int rows[9] = {0};
    unsigned int cols[9] = {0};
    unsigned int boxes[9] = {0};
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            // Check if the position is filled with number
            if (board[r][c] == '.') {
                continue;
            }
            int val = board[r][c] - '0';
            unsigned int pos = 1 << (val - 1);
            // Check the row
            if (rows[r] & pos) {
                return false;
            }
            rows[r] |= pos;
            // Check the column
            if (cols[c] & pos) {
                return false;
            }
            cols[c] |= pos;
            // Check the box
            int idx = (r / 3) * 3 + c / 3;
            if (boxes[idx] & pos) {
                return false;
            }
            boxes[idx] |= pos;
        }
    }
    return true;
}
