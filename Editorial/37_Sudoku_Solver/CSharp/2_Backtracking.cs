public class Solution {
    // box size
    int n;

    // row size
    int N;
    int[][] rows;
    int[][] columns;
    int[][] boxes;
    char[][] board;
    bool sudokuSolved = false;

    public Solution() {
        n = 3;
        N = n * n;
        rows = new int [N][];
        columns = new int [N][];
        boxes = new int [N][];
        for (int k = 0; k < N; k++) {
            rows[k] = new int[N + 1];
            columns[k] = new int[N + 1];
            boxes[k] = new int[N + 1];
        }
    }

    public bool CouldPlace(int d, int row, int col) {
        int idx = (row / n) * n + col / n;
        return rows[row][d] + columns[col][d] + boxes[idx][d] == 0;
    }

    public void PlaceNumber(int d, int row, int col) {
        int idx = (row / n) * n + col / n;
        rows[row][d]++;
        columns[col][d]++;
        boxes[idx][d]++;
        board[row][col] = (char)(d + '0');
    }

    public void RemoveNumber(int d, int row, int col) {
        int idx = (row / n) * n + col / n;
        rows[row][d]--;
        columns[col][d]--;
        boxes[idx][d]--;
        board[row][col] = '.';
    }

    public void PlaceNextNumbers(int row, int col) {
        if ((col == N - 1) && (row == N - 1)) {
            sudokuSolved = true;
        } else {
            if (col == N - 1)
                Backtrack(row + 1, 0);
            else
                Backtrack(row, col + 1);
        }
    }

    public void Backtrack(int row, int col) {
        if (board[row][col] == '.') {
            for (int d = 1; d < 10; d++) {
                if (CouldPlace(d, row, col)) {
                    PlaceNumber(d, row, col);
                    PlaceNextNumbers(row, col);
                    if (!sudokuSolved)
                        RemoveNumber(d, row, col);
                }
            }
        } else
            PlaceNextNumbers(row, col);
    }

    public void SolveSudoku(char[][] board) {
        this.board = board;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                char num = board[i][j];
                if (num != '.') {
                    int d = (int)char.GetNumericValue(num);
                    PlaceNumber(d, i, j);
                }
            }
        }

        Backtrack(0, 0);
    }
}
