public class Solution {
    public int NumberOfSubmatrices(char[][] grid) {
        int n = grid.Length, m = grid[0].Length;
        int ans = 0;
        int[,,] sum = new int[n + 1, m + 1, 2];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'X') {
                    sum[i + 1, j + 1, 0] =
                        sum[i + 1, j, 0] + sum[i, j + 1, 0] - sum[i, j, 0] + 1;
                    sum[i + 1, j + 1, 1] = 1;
                } else if (grid[i][j] == 'Y') {
                    sum[i + 1, j + 1, 0] =
                        sum[i + 1, j, 0] + sum[i, j + 1, 0] - sum[i, j, 0] - 1;
                    sum[i + 1, j + 1, 1] =
                        (sum[i + 1, j, 1] | sum[i, j + 1, 1]) == 1 ? 1 : 0;
                } else {
                    sum[i + 1, j + 1, 0] =
                        sum[i + 1, j, 0] + sum[i, j + 1, 0] - sum[i, j, 0];
                    sum[i + 1, j + 1, 1] =
                        (sum[i + 1, j, 1] | sum[i, j + 1, 1]) == 1 ? 1 : 0;
                }

                if (sum[i + 1, j + 1, 0] == 0 && sum[i + 1, j + 1, 1] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
}
