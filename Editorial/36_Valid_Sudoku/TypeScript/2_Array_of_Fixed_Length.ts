function isValidSudoku(board: string[][]): boolean {
    let N = 9;
    let rows: number[][] = Array.from({ length: N }, () => Array(N).fill(0));
    let cols: number[][] = Array.from({ length: N }, () => Array(N).fill(0));
    let boxes: number[][] = Array.from({ length: N }, () => Array(N).fill(0));
    for (let r = 0; r < N; r++) {
        for (let c = 0; c < N; c++) {
            if (board[r][c] == ".") {
                continue;
            }
            let pos: number = parseInt(board[r][c]) - 1;
            if (rows[r][pos] == 1) {
                return false;
            }
            rows[r][pos] = 1;
            if (cols[c][pos] == 1) {
                return false;
            }
            cols[c][pos] = 1;
            let idx: number = Math.floor(r / 3) * 3 + Math.floor(c / 3);
            if (boxes[idx][pos] == 1) {
                return false;
            }
            boxes[idx][pos] = 1;
        }
    }
    return true;
}
