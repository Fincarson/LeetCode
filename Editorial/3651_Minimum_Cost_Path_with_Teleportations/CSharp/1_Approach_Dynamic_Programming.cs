public class Solution {
    public int MinCost(int[][] grid, int k) {
        int m = grid.Length, n = grid[0].Length;
        var points = new List<(int, int)>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                points.Add((i, j));
            }
        }
        points.Sort((p1, p2) => grid[p1.Item1][p1.Item2].CompareTo(
                        grid[p2.Item1][p2.Item2]));
        int[,] costs = new int[m, n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                costs[i, j] = int.MaxValue;
            }
        }
        for (int t = 0; t <= k; t++) {
            int minCost = int.MaxValue;
            for (int i = 0, j = 0; i < points.Count; i++) {
                minCost =
                    Math.Min(minCost, costs[points[i].Item1, points[i].Item2]);
                if (i + 1 < points.Count &&
                    grid[points[i].Item1][points[i].Item2] ==
                        grid[points[i + 1].Item1][points[i + 1].Item2]) {
                    continue;
                }
                for (int r = j; r <= i; r++) {
                    costs[points[r].Item1, points[r].Item2] = minCost;
                }
                j = i + 1;
            }
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i == m - 1 && j == n - 1) {
                        costs[i, j] = 0;
                        continue;
                    }
                    if (i != m - 1) {
                        costs[i, j] = Math.Min(
                            costs[i, j], costs[i + 1, j] + grid[i + 1][j]);
                    }
                    if (j != n - 1) {
                        costs[i, j] = Math.Min(
                            costs[i, j], costs[i, j + 1] + grid[i][j + 1]);
                    }
                }
            }
        }
        return costs[0, 0];
    }
}
