public class Solution {
    public int[][] RangeAddQueries(int n, int[][] queries) {
        int[][] diff = new int [n + 1][];
        for (int i = 0; i <= n; i++) {
            diff[i] = new int[n + 1];
        }

        foreach (var q in queries) {
            int row1 = q[0], col1 = q[1], row2 = q[2], col2 = q[3];
            diff[row1][col1] += 1;
            diff[row2 + 1][col1] -= 1;
            diff[row1][col2 + 1] -= 1;
            diff[row2 + 1][col2 + 1] += 1;
        }

        int[][] mat = new int [n][];
        for (int i = 0; i < n; i++) {
            mat[i] = new int[n];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x1 = (i == 0) ? 0 : mat[i - 1][j];
                int x2 = (j == 0) ? 0 : mat[i][j - 1];
                int x3 = (i == 0 || j == 0) ? 0 : mat[i - 1][j - 1];
                mat[i][j] = diff[i][j] + x1 + x2 - x3;
            }
        }
        return mat;
    }
}
