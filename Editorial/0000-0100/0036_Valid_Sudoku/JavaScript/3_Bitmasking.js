var isValidSudoku = function (board) {
    let N = 9;
    // Use a binary number to record previous occurrence
    let rows = Array(N).fill(0);
    let cols = Array(N).fill(0);
    let boxes = Array(N).fill(0);
    for (let r = 0; r < N; r++) {
        for (let c = 0; c < N; c++) {
            // Check if the position is filled with number
            if (board[r][c] === ".") {
                continue;
            }
            let pos = 1 << (Number(board[r][c]) - 1);
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
            let idx = parseInt(r / 3) * 3 + parseInt(c / 3);
            if (boxes[idx] & pos) {
                return false;
            }
            boxes[idx] |= pos;
        }
    }
    return true;
};
