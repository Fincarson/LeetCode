public class Solution {
    public bool CanPartitionGrid(int[][] grid) {
        long total = 0;
        int m = grid.Length;
        int n = grid[0].Length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }
        for (int k = 0; k < 4; k++) {
            HashSet<long> exist = new HashSet<long>();
            exist.Add(0);
            long sum = 0;
            m = grid.Length;
            n = grid[0].Length;
            if (m < 2) {
                grid = Rotation(grid);
                continue;
            }
            if (n == 1) {
                for (int i = 0; i < m - 1; i++) {
                    sum += grid[i][0];
                    long tag = sum * 2 - total;
                    if (tag == 0 || tag == grid[0][0] || tag == grid[i][0]) {
                        return true;
                    }
                }
                grid = Rotation(grid);
                continue;
            }
            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n; j++) {
                    exist.Add(grid[i][j]);
                    sum += grid[i][j];
                }
                long tag = sum * 2 - total;
                if (i == 0) {
                    if (tag == 0 || tag == grid[0][0] ||
                        tag == grid[0][n - 1]) {
                        return true;
                    }
                    continue;
                }
                if (exist.Contains(tag)) {
                    return true;
                }
            }
            grid = Rotation(grid);
        }
        return false;
    }

    public int[][] Rotation(int[][] grid) {
        int m = grid.Length, n = grid[0].Length;
        int[][] tmp = new int [n][];
        for (int i = 0; i < n; i++) {
            tmp[i] = new int[m];
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp[j][m - 1 - i] = grid[i][j];
            }
        }
        return tmp;
    }
}
