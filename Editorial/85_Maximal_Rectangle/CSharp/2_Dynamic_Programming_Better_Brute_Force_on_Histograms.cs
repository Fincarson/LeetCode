public class Solution {
    public int MaximalRectangle(char[][] matrix) {
        if (matrix.Length == 0)
            return 0;
        int maxarea = 0;
        int[][] dp = new int [matrix.Length][];
        for (int a = 0; a < dp.Length; a++) dp[a] = new int[matrix[0].Length];
        for (int i = 0; i < matrix.Length; i++) {
            for (int j = 0; j < matrix[0].Length; j++) {
                if (matrix[i][j] == '1') {
                    // compute the maximum width and update dp with it
                    dp[i][j] = j == 0 ? 1 : dp[i][j - 1] + 1;
                    int width = dp[i][j];
                    // compute the maximum area rectangle with a lower right
                    // corner at [i, j]
                    for (int k = i; k >= 0; k--) {
                        width = Math.Min(width, dp[k][j]);
                        maxarea = Math.Max(maxarea, width * (i - k + 1));
                    }
                }
            }
        }

        return maxarea;
    }
}
