public class Solution {
    private char[][] board;
    private int rows;
    private int cols;

    public bool Exist(char[][] board, string word) {
        this.board = board;
        this.rows = board.Length;
        this.cols = board[0].Length;

        for (int row = 0; row < this.rows; row++) {
            for (int col = 0; col < this.cols; col++) {
                if (Backtrack(row, col, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    private bool Backtrack(int row, int col, string word, int index) {
        // Step 1: Check if the last character matches
        if (index >= word.Length) {
            return true;
        }

        // Step 2: Check boundaries
        if (row < 0 || row == this.rows || col < 0 || col == this.cols ||
            this.board[row][col] != word[index]) {
            return false;
        }

        // Step 3: Explore the neighbors in DFS
        bool ret = false;
        // Mark the path before the next exploration
        char temp = this.board[row][col];
        this.board[row][col] = '#';

        int[] rowOffsets = { 0, 1, 0, -1 };
        int[] colOffsets = { 1, 0, -1, 0 };
        for (int d = 0; d < 4; d++) {
            ret = Backtrack(row + rowOffsets[d], col + colOffsets[d], word,
                            index + 1);
            if (ret)
                break;
        }

        // Step 4: Clean up and return false
        this.board[row][col] = temp;
        return ret;
    }
}
