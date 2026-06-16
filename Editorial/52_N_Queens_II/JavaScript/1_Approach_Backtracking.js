var totalNQueens = function (n) {
    function backtrack(row, diagonals, anti_diagonals, cols) {
        if (row == n) {
            return 1;
        }
        let solutions = 0;
        for (let col = 0; col < n; col++) {
            let curr_diagonal = row - col;
            let curr_anti_diagonal = row + col;
            // If the queen is not placeable
            if (
                cols.has(col) ||
                diagonals.has(curr_diagonal) ||
                anti_diagonals.has(curr_anti_diagonal)
            ) {
                continue;
            }
            cols.add(col);
            diagonals.add(curr_diagonal);
            anti_diagonals.add(curr_anti_diagonal);
            solutions += backtrack(row + 1, diagonals, anti_diagonals, cols);
            cols.delete(col);
            diagonals.delete(curr_diagonal);
            anti_diagonals.delete(curr_anti_diagonal);
        }
        return solutions;
    }
    return backtrack(0, new Set(), new Set(), new Set());
};
