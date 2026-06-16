var solveNQueens = function (n) {
    const solutions = [];
    const emptyBoard = Array.from({ length: n }, () => Array(n).fill("."));
    // Making use of a helper function to get the
    // solutions in the correct output format
    const createBoard = (state) => {
        const board = [];
        for (let row = 0; row < n; row++) {
            board.push(state[row].join(""));
        }
        return board;
    };
    const backtrack = (row, diagonals, antiDiagonals, cols, state) => {
        // Base case - N queens have been placed
        if (row === n) {
            solutions.push(createBoard(state));
            return;
        }
        for (let col = 0; col < n; col++) {
            const currDiagonal = row - col;
            const currAntiDiagonal = row + col;
            // If the queen is not placeable
            if (
                cols.has(col) ||
                diagonals.has(currDiagonal) ||
                antiDiagonals.has(currAntiDiagonal)
            ) {
                continue;
            }
            // "Add" the queen to the board
            cols.add(col);
            diagonals.add(currDiagonal);
            antiDiagonals.add(currAntiDiagonal);
            state[row][col] = "Q";
            // Move on to the next row with the updated board state
            backtrack(row + 1, diagonals, antiDiagonals, cols, state);
            // "Remove" the queen from the board since we have already
            // explored all valid paths using the above function call
            cols.delete(col);
            diagonals.delete(currDiagonal);
            antiDiagonals.delete(currAntiDiagonal);
            state[row][col] = ".";
        }
    };
    backtrack(0, new Set(), new Set(), new Set(), emptyBoard);
    return solutions;
};
