public class Solution {
    public void Solve(char[][] board) {
        if (board == null || board.Length == 0) {
            return;
        }

        this.ROWS = board.Length;
        this.COLS = board[0].Length;
        List<int[]> borders = new List<int[]>();
        // Step 1). construct the list of border cells to iterate over
        for (int r = 0; r < this.ROWS; ++r) {
            borders.Add(new int[] { r, 0 });
            borders.Add(new int[] { r, this.COLS - 1 });
        }

        for (int c = 0; c < this.COLS; ++c) {
            borders.Add(new int[] { 0, c });
            borders.Add(new int[] { this.ROWS - 1, c });
        }

        // Step 2). mark the escaped cells
        foreach (var pair in borders) {
            this.DFS(board, pair[0], pair[1]);
        }

        // Step 3). flip the cells to their correct final states
        for (int r = 0; r < this.ROWS; ++r) {
            for (int c = 0; c < this.COLS; ++c) {
                if (board[r][c] == 'O')
                    board[r][c] = 'X';
                if (board[r][c] == 'E')
                    board[r][c] = 'O';
            }
        }
    }

    int ROWS, COLS;

    protected void DFS(char[][] board, int row, int col) {
        if (board[row][col] != 'O')
            return;
        board[row][col] = 'E';
        if (col < this.COLS - 1)
            DFS(board, row, col + 1);
        if (row < this.ROWS - 1)
            DFS(board, row + 1, col);
        if (col > 0)
            DFS(board, row, col - 1);
        if (row > 0)
            DFS(board, row - 1, col);
    }
}
