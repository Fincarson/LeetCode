bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int ROWS = boardSize;
    int COLS = *boardColSize;
    bool backtrack(int row, int col, char* suffix) {
        /* Step 1). check the bottom case. */
        if (strlen(suffix) == 0) return true;
        /* Step 2). Check the boundaries. */
        if (row < 0 || row == ROWS || col < 0 || col == COLS ||
            board[row][col] != suffix[0])
            return false;
        /* Step 3). explore the neighbors in DFS */
        bool ret = false;
        // mark the path before the next exploration
        board[row][col] = '#';
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int d = 0; d < 4; ++d) {
            ret = backtrack(row + directions[d][0], col + directions[d][1],
                            suffix + 1);
            if (ret) break;
        }
        /* Step 4). clean up and return the result. */
        board[row][col] = suffix[0];
        return ret;
    }

    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            if (backtrack(row, col, word)) return true;
        }
    }
    return false;
};
