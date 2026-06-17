public class Solution {
    private int ROWS;
    private int COLS;

    public void Solve(char[][] board) {
        if (board == null || board.Length == 0) {
            return;
        }

        this.ROWS = board.Length;
        this.COLS = board[0].Length;
        List<Pair<int, int>> borders = new List<Pair<int, int>>();
        for (int r = 0; r < this.ROWS; ++r) {
            borders.Add(new Pair<int, int>(r, 0));
            borders.Add(new Pair<int, int>(r, this.COLS - 1));
        }

        for (int c = 0; c < this.COLS; ++c) {
            borders.Add(new Pair<int, int>(0, c));
            borders.Add(new Pair<int, int>(this.ROWS - 1, c));
        }

        foreach (Pair<int, int> pair in borders) {
            this.BFS(board, pair.first, pair.second);
        }

        for (int r = 0; r < this.ROWS; ++r) {
            for (int c = 0; c < this.COLS; ++c) {
                if (board[r][c] == 'O')
                    board[r][c] = 'X';
                if (board[r][c] == 'E')
                    board[r][c] = 'O';
            }
        }
    }

    protected void BFS(char[][] board, int r, int c) {
        Queue<Pair<int, int>> queue = new Queue<Pair<int, int>>();
        queue.Enqueue(new Pair<int, int>(r, c));
        while (queue.Count > 0) {
            Pair<int, int> pair = queue.Dequeue();
            int row = pair.first, col = pair.second;
            if (board[row][col] != 'O')
                continue;
            board[row][col] = 'E';
            if (col < this.COLS - 1)
                queue.Enqueue(new Pair<int, int>(row, col + 1));
            if (row < this.ROWS - 1)
                queue.Enqueue(new Pair<int, int>(row + 1, col));
            if (col > 0)
                queue.Enqueue(new Pair<int, int>(row, col - 1));
            if (row > 0)
                queue.Enqueue(new Pair<int, int>(row - 1, col));
        }
    }
}

public class Pair<T1, T2> {
    public T1 first;
    public T2 second;

    public Pair(T1 first, T2 second) {
        this.first = first;
        this.second = second;
    }
}
