class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();

        // Create a vector nums that stores the values of the matrix and their
        // indices.
        vector<tuple<int, int, int>> nums;

        // Create rows and cols to store the minimum values for every row and
        // column.
        vector<int> rows(row, 1);
        vector<int> cols(col, 1);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                nums.push_back(make_tuple(grid[i][j], i, j));
            }
        }
        sort(nums.begin(), nums.end());

        for (auto tup : nums) {
            int val, x, y;
            tie(val, x, y) = tup;
            // Find the maximum value of rows[x] and cols[y] till now and assign
            // it to val.
            val = max(rows[x], cols[y]);
            grid[x][y] = val;
            // Update the new maximum value in rows[x] and cols[y].
            rows[x] = cols[y] = val + 1;
        }
        return grid;
    }
};
