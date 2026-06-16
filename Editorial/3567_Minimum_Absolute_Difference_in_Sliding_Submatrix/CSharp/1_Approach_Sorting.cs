public class Solution {
    public int[][] MinAbsDiff(int[][] grid, int k) {
        int m = grid.Length, n = grid[0].Length;
        int[][] res = new int [m - k + 1][];
        for (int i = 0; i < m - k + 1; i++) {
            res[i] = new int[n - k + 1];
        }
        for (int i = 0; i + k <= m; i++) {
            for (int j = 0; j + k <= n; j++) {
                List<int> kgrid = new List<int>();
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        kgrid.Add(grid[x][y]);
                    }
                }
                int kmin = int.MaxValue;
                kgrid.Sort();
                for (int t = 1; t < kgrid.Count; t++) {
                    if (kgrid[t] == kgrid[t - 1]) {
                        continue;
                    }
                    kmin = Math.Min(kmin, kgrid[t] - kgrid[t - 1]);
                }
                if (kmin != int.MaxValue) {
                    res[i][j] = kmin;
                }
            }
        }
        return res;
    }
}
