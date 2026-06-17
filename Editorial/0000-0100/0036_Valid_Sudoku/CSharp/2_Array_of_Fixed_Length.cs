public class Solution {
    public bool IsValidSudoku(char[][] board) {
        int N = 9;
        // Use an array to record the status
        int[][] rows = new int [N][];
        int[][] cols = new int [N][];
        int[][] boxes = new int [N][];
        for (int i = 0; i < N; i++) {
            rows[i] = new int[N];
            cols[i] = new int[N];
            boxes[i] = new int[N];
        }

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                // Check if the position is filled with number
                if (board[r][c] == '.') {
                    continue;
                }

                int pos = board[r][c] - '1';
                // Check the row
                if (rows[r][pos] == 1) {
                    return false;
                }

                rows[r][pos] = 1;
                // Check the column
                if (cols[c][pos] == 1) {
                    return false;
                }

                cols[c][pos] = 1;
                // Check the box
                int idx = (r / 3) * 3 + c / 3;
                if (boxes[idx][pos] == 1) {
                    return false;
                }

                boxes[idx][pos] = 1;
            }
        }

        return true;
    }
}
