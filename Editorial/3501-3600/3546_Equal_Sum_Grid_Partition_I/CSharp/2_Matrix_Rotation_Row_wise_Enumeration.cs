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
        for (int k = 0; k < 2; k++) {
            long sum = 0;
            m = grid.Length;
            n = grid[0].Length;
            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n; j++) {
                    sum += grid[i][j];
                }
                if (sum * 2 == total) {
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
