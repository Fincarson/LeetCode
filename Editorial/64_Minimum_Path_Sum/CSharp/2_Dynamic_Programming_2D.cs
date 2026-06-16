public class Solution {
    public int MinPathSum(int[][] grid) {
        int[][] dp = new int [grid.Length][];
        for (int i = 0; i < grid.Length; i++) dp[i] = new int[grid[0].Length];
        for (int i = grid.Length - 1; i >= 0; i--) {
            for (int j = grid[0].Length - 1; j >= 0; j--) {
                if (i == grid.Length - 1 && j != grid[0].Length - 1)
                    dp[i][j] = grid[i][j] + dp[i][j + 1];
                else if (j == grid[0].Length - 1 && i != grid.Length - 1)
                    dp[i][j] = grid[i][j] + dp[i + 1][j];
                else if (j != grid[0].Length - 1 && i != grid.Length - 1)
                    dp[i][j] =
                        grid[i][j] + Math.Min(dp[i + 1][j], dp[i][j + 1]);
                else
                    dp[i][j] = grid[i][j];
            }
        }

        return dp[0][0];
    }
}
