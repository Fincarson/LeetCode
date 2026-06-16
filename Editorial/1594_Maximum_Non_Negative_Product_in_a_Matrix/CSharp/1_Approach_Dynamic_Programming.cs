public class Solution {
    public int MaxProductPath(int[][] grid) {
        const int MOD = 1000000007;
        int m = grid.Length, n = grid[0].Length;
        long[,] maxgt = new long[m, n];
        long[,] minlt = new long[m, n];

        maxgt[0, 0] = minlt[0, 0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            maxgt[0, i] = minlt[0, i] = maxgt[0, i - 1] * grid[0][i];
        }
        for (int i = 1; i < m; i++) {
            maxgt[i, 0] = minlt[i, 0] = maxgt[i - 1, 0] * grid[i][0];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] >= 0) {
                    long maxPrev = Math.Max(maxgt[i, j - 1], maxgt[i - 1, j]);
                    long minPrev = Math.Min(minlt[i, j - 1], minlt[i - 1, j]);
                    maxgt[i, j] = maxPrev * grid[i][j];
                    minlt[i, j] = minPrev * grid[i][j];
                } else {
                    long maxPrev = Math.Max(maxgt[i, j - 1], maxgt[i - 1, j]);
                    long minPrev = Math.Min(minlt[i, j - 1], minlt[i - 1, j]);
                    maxgt[i, j] = minPrev * grid[i][j];
                    minlt[i, j] = maxPrev * grid[i][j];
                }
            }
        }

        if (maxgt[m - 1, n - 1] < 0) {
            return -1;
        } else {
            return (int)(maxgt[m - 1, n - 1] % MOD);
        }
    }
}
