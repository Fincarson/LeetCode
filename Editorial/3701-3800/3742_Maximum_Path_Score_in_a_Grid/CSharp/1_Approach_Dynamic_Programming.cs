public class Solution {
    public int MaxPathScore(int[][] grid, int k) {
        int m = grid.Length, n = grid[0].Length;

        int[,,] dp = new int[m, n, k + 1];

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int c = 0; c <= k; c++) dp[i, j, c] = int.MinValue;

        dp[0, 0, 0] = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int c = 0; c <= k; c++) {
                    if (dp[i, j, c] == int.MinValue)
                        continue;

                    if (i + 1 < m) {
                        int val = grid[i + 1][j];
                        int cost = val == 0 ? 0 : 1;
                        if (c + cost <= k) {
                            dp[i + 1, j, c + cost] = Math.Max(
                                dp[i + 1, j, c + cost], dp[i, j, c] + val);
                        }
                    }

                    if (j + 1 < n) {
                        int val = grid[i][j + 1];
                        int cost = val == 0 ? 0 : 1;
                        if (c + cost <= k) {
                            dp[i, j + 1, c + cost] = Math.Max(
                                dp[i, j + 1, c + cost], dp[i, j, c] + val);
                        }
                    }
                }
            }
        }

        int ans = int.MinValue;
        for (int c = 0; c <= k; c++) {
            ans = Math.Max(ans, dp[m - 1, n - 1, c]);
        }

        return ans < 0 ? -1 : ans;
    }
}
