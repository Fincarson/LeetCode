public class Solution {
    private int Calculate(int[][] grid, int i, int j) {
        if (i == grid.Length || j == grid[0].Length)
            return int.MaxValue;
        if (i == grid.Length - 1 && j == grid[0].Length - 1)
            return grid[i][j];
        return grid[i][j] +
               Math.Min(Calculate(grid, i + 1, j), Calculate(grid, i, j + 1));
    }

    public int MinPathSum(int[][] grid) {
        return Calculate(grid, 0, 0);
    }
}
