public class Solution {
    public int[][] GenerateMatrix(int n) {
        int[][] res = new int [n][];
        for (int i = 0; i < n; i++) res[i] = new int[n];
        int[][] helpers =
            new int [4][] { new int[2] { 0, 1 }, new int[2] { 1, 0 },
                            new int[2] { 0, -1 }, new int[2] { -1, 0 } };
        int val = 1, d = 0, row = 0, col = 0;
        while (val <= n * n) {
            res[row][col] = val++;
            int r = (row + helpers[d][0] + n) % n;
            int c = (col + helpers[d][1] + n) % n;
            if (res[r][c] != 0)
                d = (d + 1) % 4;
            row += helpers[d][0];
            col += helpers[d][1];
        }

        return res;
    }
}
