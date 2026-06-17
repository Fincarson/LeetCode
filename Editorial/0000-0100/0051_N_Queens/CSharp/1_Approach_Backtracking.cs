public class Solution {
    private int size;
    private List<IList<string>> solutions = new List<IList<string>>();

    public IList<IList<string>> SolveNQueens(int n) {
        size = n;
        char[][] emptyBoard = new char [size][];
        for (int i = 0; i < n; i++) {
            emptyBoard[i] = new char[size];
            for (int j = 0; j < n; j++) {
                emptyBoard[i][j] = '.';
            }
        }

        Backtrack(0, new HashSet<int>(), new HashSet<int>(), new HashSet<int>(),
                  emptyBoard);
        return solutions;
    }

    // Making use of a helper function to get the
    // solutions in the correct output format
    private List<string> CreateBoard(char[][] state) {
        List<string> board = new List<string>();
        for (int row = 0; row < size; row++) {
            string current_row = new string(state[row]);
            board.Add(current_row);
        }

        return board;
    }

    private void Backtrack(int row, HashSet<int> diagonals,
                           HashSet<int> antiDiagonals, HashSet<int> cols,
                           char[][] state) {
        // Base case - N queens have been placed
        if (row == size) {
            solutions.Add(CreateBoard(state));
            return;
        }

        for (int col = 0; col < size; col++) {
            int currDiagonal = row - col;
            int currAntiDiagonal = row + col;
            // If the queen is not placeable
            if (cols.Contains(col) || diagonals.Contains(currDiagonal) ||
                antiDiagonals.Contains(currAntiDiagonal)) {
                continue;
            }

            // "Add" the queen to the board
            cols.Add(col);
            diagonals.Add(currDiagonal);
            antiDiagonals.Add(currAntiDiagonal);
            state[row][col] = 'Q';
            // Move on to the next row with the updated board state
            Backtrack(row + 1, diagonals, antiDiagonals, cols, state);
            // "Remove" the queen from the board since we have already
            // explored all valid paths using the above function call
            cols.Remove(col);
            diagonals.Remove(currDiagonal);
            antiDiagonals.Remove(currAntiDiagonal);
            state[row][col] = '.';
        }
    }
}
