function solve(board: string[][]): void {
    if (board == null || board.length == 0) {
        return;
    }
    let ROWS = board.length;
    let COLS = board[0].length;
    let borders = [];
    for (let r = 0; r < ROWS; ++r) {
        borders.push([r, 0]);
        borders.push([r, COLS - 1]);
    }
    for (let c = 0; c < COLS; ++c) {
        borders.push([0, c]);
        borders.push([ROWS - 1, c]);
    }
    borders.forEach((pair) => {
        dfs(board, pair[0], pair[1]);
    });
    for (let r = 0; r < ROWS; ++r) {
        for (let c = 0; c < COLS; ++c) {
            if (board[r][c] == "O") board[r][c] = "X";
            if (board[r][c] == "E") board[r][c] = "O";
        }
    }
    function dfs(board: string[][], row: number, col: number): void {
        if (board[row][col] != "O") return;
        board[row][col] = "E";
        if (col < COLS - 1) dfs(board, row, col + 1);
        if (row < ROWS - 1) dfs(board, row + 1, col);
        if (col > 0) dfs(board, row, col - 1);
        if (row > 0) dfs(board, row - 1, col);
    }
}
