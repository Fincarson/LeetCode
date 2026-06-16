var exist = function (board, word) {
    const ROWS = board.length;
    const COLS = board[0].length;
    const backtrack = function (row, col, suffix) {
        /* Step 1). check the bottom case. */
        if (suffix.length == 0) return true;
        /* Step 2). Check the boundaries. */
        if (
            row < 0 ||
            row == ROWS ||
            col < 0 ||
            col == COLS ||
            board[row][col] != suffix.charAt(0)
        )
            return false;
        /* Step 3). explore the neighbors in DFS */
        let ret = false;
        // mark the path before the next exploration
        board[row][col] = "#";
        const directions = [
            [0, 1],
            [1, 0],
            [0, -1],
            [-1, 0],
        ];
        for (let [rowOffset, colOffset] of directions) {
            ret = backtrack(row + rowOffset, col + colOffset, suffix.slice(1));
            if (ret) break;
        }
        /* Step 4). clean up and return the result. */
        board[row][col] = suffix.charAt(0);
        return ret;
    };

    for (let row = 0; row < ROWS; ++row) {
        for (let col = 0; col < COLS; ++col) {
            if (backtrack(row, col, word)) return true;
        }
    }
    return false;
};
