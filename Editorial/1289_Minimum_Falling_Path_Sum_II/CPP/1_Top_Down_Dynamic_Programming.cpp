class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        // Initialize a hash map to cache the result of each sub-problem
        map<pair<int, int>, int> memo;

        // We can select any element from the first row. We will select
        // the element which leads to minimum sum.
        int answer = INT_MAX;
        for (int col = 0; col < grid.size(); col++) {
            answer = min(answer, optimal(0, col, grid, memo));
        }

        // Return the minimum sum
        return answer;
    }

    // The optimal(row, col) function returns the minimum sum of a
    // falling path with non-zero shifts, starting from grid[row][col]
    int optimal(int row, int col, vector<vector<int>>& grid, map<pair<int, int>, int>& memo) {
        // If the last row, then return the value of the cell itself
        if (row == grid.size() - 1) {
            return grid[row][col];
        }

        // If the result of this sub-problem is already cached
        if (memo.find({row, col}) != memo.end()) {
            return memo[{row, col}];
        }

        // Select grid[row][col], and move on to next row. For next
        // row, choose the cell that leads to the minimum sum
        int nextMinimum = INT_MAX;
        for (int nextRowCol = 0; nextRowCol < grid.size(); nextRowCol++) {
            if (nextRowCol != col) {
                nextMinimum = min(nextMinimum, optimal(row + 1, nextRowCol, grid, memo));
            }
        }

        // Minimum cost from this cell
        memo[{row, col}] = grid[row][col] + nextMinimum;
        return memo[{row, col}];
    }
};
