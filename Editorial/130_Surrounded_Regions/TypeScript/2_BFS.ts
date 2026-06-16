var solve = function (board: Array<Array<string>>): void {
    if (!board || !board[0]) {
        return;
    }
    const ROWS: number = board.length;
    const COLS: number = board[0].length;
    let borders: number[][] = Array.from({ length: ROWS }, (v, i) => i)
        .map((i) => [
            [i, 0],
            [i, COLS - 1],
        ])
        .concat(
            Array.from({ length: COLS }, (v, i) => i).map((i) => [
                [0, i],
                [ROWS - 1, i],
            ]),
        )
        .flat();
    borders.forEach(([row, col]) => BFS(board, row, col, ROWS, COLS));
    for (let row = 0; row < ROWS; ++row)
        for (let col = 0; col < COLS; ++col) {
            if (board[row][col] == "O") board[row][col] = "X";
            if (board[row][col] == "E") board[row][col] = "O";
        }
};
var BFS = function (
    board: Array<Array<string>>,
    row: number,
    col: number,
    ROWS: number,
    COLS: number,
): void {
    let queue: number[][] = [[row, col]];
    while (queue.length) {
        let [row, col] = queue.shift() as number[];
        if (board[row][col] !== "O") {
            continue;
        }
        board[row][col] = "E"; // Mark this cell as escaped
        if (col < COLS - 1) queue.push([row, col + 1]);
        if (row < ROWS - 1) queue.push([row + 1, col]);
        if (col > 0) queue.push([row, col - 1]);
        if (row > 0) queue.push([row - 1, col]);
    }
};
