class Solution {
public:
    vector<vector<int>> rotation(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector tmp(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp[j][m - 1 - i] = grid[i][j];
            }
        }
        return tmp;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total = 0;
        long long sum;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }
        for (int k = 0; k < 2; k++) {
            sum = 0;
            m = grid.size();
            n = grid[0].size();
            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n; j++) {
                    sum += grid[i][j];
                }
                if (sum * 2 == total) {
                    return true;
                }
            }
            grid = rotation(grid);
        }
        return false;
    }
};
