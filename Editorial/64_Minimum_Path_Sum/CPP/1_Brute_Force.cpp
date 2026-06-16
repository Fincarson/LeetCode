class Solution {
public:
    int calculate(vector<vector<int>>& grid, int i, int j) {
        if (i == grid.size() || j == grid[0].size()) return INT_MAX;
        if (i == grid.size() - 1 && j == grid[0].size() - 1) return grid[i][j];
        return grid[i][j] +
               min(calculate(grid, i + 1, j), calculate(grid, i, j + 1));
    }
    int minPathSum(vector<vector<int>>& grid) { return calculate(grid, 0, 0); }
};
