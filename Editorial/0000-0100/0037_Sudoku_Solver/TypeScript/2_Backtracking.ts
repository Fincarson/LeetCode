function solveSudoku(board: string[][]): void {
    let n: number = 3;
    let N: number = n * n;
    let boxIndex = (row: number, col: number): number =>
        Math.floor(row / n) * n + Math.floor(col / n);
    let rows: Map<number, number>[] = Array(N)
        .fill(null)
        .map(() => new Map<number, number>());
    let columns: Map<number, number>[] = Array(N)
        .fill(null)
        .map(() => new Map<number, number>());
    let boxes: Map<number, number>[] = Array(N)
        .fill(null)
        .map(() => new Map<number, number>());
    for (let i = 0; i < N; i++) {
        for (let j = 0; j < N; j++) {
            if (board[i][j] !== ".") {
                let d: number = Number(board[i][j]);
                placeNumber(d, i, j, rows, columns, boxes, boxIndex, board);
            }
        }
    }
    solve(board, 0, 0, rows, columns, boxes, boxIndex);
}
function solve(
    board: string[][],
    row: number,
    col: number,
    rows: Map<number, number>[],
    columns: Map<number, number>[],
    boxes: Map<number, number>[],
    boxIndex,
): boolean {
    if (col === board[row].length) {
        row++;
        col = 0;
    }
    if (row === board.length) {
        return true;
    }
    if (board[row][col] !== ".") {
        return solve(board, row, col + 1, rows, columns, boxes, boxIndex);
    }
    for (let num = 1; num <= 9; num++) {
        let digit = num.toString();
        if (couldPlace(num, row, col, rows, columns, boxes, boxIndex)) {
            placeNumber(num, row, col, rows, columns, boxes, boxIndex, board);
            if (solve(board, row, col + 1, rows, columns, boxes, boxIndex)) {
                return true;
            }
            removeNumber(num, row, col, rows, columns, boxes, boxIndex, board);
        }
    }
    return false;
}
function couldPlace(
    d: number,
    row: number,
    col: number,
    rows: Map<number, number>[],
    columns: Map<number, number>[],
    boxes: Map<number, number>[],
    boxIndex,
): boolean {
    let res: boolean = !(
        rows[row].has(d) ||
        columns[col].has(d) ||
        boxes[boxIndex(row, col)].has(d)
    );
    return res;
}
function placeNumber(
    d: number,
    row: number,
    col: number,
    rows: Map<number, number>[],
    columns: Map<number, number>[],
    boxes: Map<number, number>[],
    boxIndex,
    board: string[][],
): void {
    rows[row].set(d, (rows[row].get(d) || 0) + 1);
    columns[col].set(d, (columns[col].get(d) || 0) + 1);
    boxes[boxIndex(row, col)].set(
        d,
        (boxes[boxIndex(row, col)].get(d) || 0) + 1,
    );
    board[row][col] = String(d);
}
function removeNumber(
    d: number,
    row: number,
    col: number,
    rows: Map<number, number>[],
    columns: Map<number, number>[],
    boxes: Map<number, number>[],
    boxIndex,
    board: string[][],
): void {
    rows[row].delete(d);
    columns[col].delete(d);
    boxes[boxIndex(row, col)].delete(d);
    board[row][col] = ".";
}
