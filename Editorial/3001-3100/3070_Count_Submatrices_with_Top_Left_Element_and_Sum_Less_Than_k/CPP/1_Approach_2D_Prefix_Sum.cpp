class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<int> cols(n);
        int res = 0;
        for (int i = 0; i < m; i++) {
            int rows = 0;
            for (int j = 0; j < n; j++) {
                cols[j] += grid[i][j];
                rows += cols[j];
                if (rows <= k) {
                    res++;
                }
            }
        }
        return res;
    }
};
