var solveSudoku = function (board) {
    let N = 9;
    let rows = Array.from({ length: N }, () => new Map());
    let columns = Array.from({ length: N }, () => new Map());
    let boxes = Array.from({ length: N }, () => new Map());
    let sudoku_solved = false;
    function box_index(row, col) {
        return Math.floor(row / 3) * 3 + Math.floor(col / 3);
    }
    function could_place(d, row, col) {
        let res = !(
            rows[row].has(String(d)) ||
            columns[col].has(String(d)) ||
            boxes[box_index(row, col)].has(String(d))
        );
        return res;
    }
    function place_number(d, row, col) {
        rows[row].set(
            String(d),
            rows[row].has(String(d)) ? rows[row].get(String(d)) + 1 : 1,
        );
        columns[col].set(
            String(d),
            columns[col].has(String(d)) ? columns[col].get(String(d)) + 1 : 1,
        );
        boxes[box_index(row, col)].set(
            String(d),
            boxes[box_index(row, col)].has(String(d))
                ? boxes[box_index(row, col)].get(String(d)) + 1
                : 1,
        );
        board[row][col] = String(d);
    }
    function remove_number(d, row, col) {
        rows[row].delete(String(d), rows[row].get(String(d)) - 1);
        columns[col].delete(String(d), columns[col].get(String(d)) - 1);
        boxes[box_index(row, col)].delete(
            String(d),
            boxes[box_index(row, col)].get(String(d)) - 1,
        );
        board[row][col] = ".";
    }
    function place_next_numbers(row, col) {
        if (col === N - 1 && row === N - 1) sudoku_solved = true;
        else {
            if (col === N - 1) backtrack(row + 1, 0);
            else backtrack(row, col + 1);
        }
    }
    function backtrack(row = 0, col = 0) {
        if (board[row][col] === ".") {
            for (let d = 1; d < 10; d++) {
                if (could_place(d, row, col)) {
                    place_number(d, row, col);
                    place_next_numbers(row, col);
                    if (!sudoku_solved) remove_number(d, row, col);
                }
            }
        } else place_next_numbers(row, col);
    }
    for (let i = 0; i < N; ++i)
        for (let j = 0; j < N; ++j)
            if (board[i][j] !== ".") place_number(parseInt(board[i][j]), i, j);
    backtrack();
};
