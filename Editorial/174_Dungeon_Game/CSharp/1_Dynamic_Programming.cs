public class Solution {
    const int inf = int.MaxValue;
    int[,] dp;
    int rows, cols;

    public int GetMinHealth(int currCell, int nextRow, int nextCol) {
        if (nextRow >= this.rows || nextCol >= this.cols)
            return inf;
        int nextCell = this.dp[nextRow, nextCol];
        // hero needs at least 1 point to survive
        return Math.Max(1, nextCell - currCell);
    }

    public int CalculateMinimumHP(int[][] dungeon) {
        this.rows = dungeon.Length;
        this.cols = dungeon[0].Length;
        this.dp = new int[rows, cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dp[i, j] = inf;
            }
        }

        int currCell, rightHealth, downHealth, nextHealth, minHealth;
        for (int row = this.rows - 1; row >= 0; --row) {
            for (int col = this.cols - 1; col >= 0; --col) {
                currCell = dungeon[row][col];

                rightHealth = GetMinHealth(currCell, row, col + 1);
                downHealth = GetMinHealth(currCell, row + 1, col);
                nextHealth = Math.Min(rightHealth, downHealth);

                if (nextHealth != inf) {
                    minHealth = nextHealth;
                } else {
                    minHealth = currCell >= 0 ? 1 : 1 - currCell;
                }

                this.dp[row, col] = minHealth;
            }
        }

        return this.dp[0, 0];
    }
}
