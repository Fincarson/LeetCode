class Solution {
private:
    // Direction arrays for moving up, down, left, right
    const vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    long long sumRemoteness(vector<vector<int>>& grid) {
        int n = grid.size();
        // Calculate total sum of all non-blocked cells
        long long totalSum = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] != -1) {
                    totalSum += grid[row][col];
                }
            }
        }

        // Calculate remoteness for each non-blocked cell
        long long result = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] > 0) {
                    result += bfs(grid, row, col, totalSum);
                }
            }
        }
        return result;
    }

private:
    // BFS to find sum and count of all cells reachable from (row, col)
    long long bfs(vector<vector<int>>& grid, int row, int col,
                  long long totalSum) {
        // Sum of values in current component
        long long compSum = grid[row][col];
        long long compSize = 1;  // Number of cells in component
        grid[row][col] = -1;     // Mark as visited

        queue<pair<int, int>> q;
        q.push({row, col});

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            // Explore all 4 directions
            for (auto& d : dir) {
                int newRow = curr.first + d[0];
                int newCol = curr.second + d[1];
                if (isValid(grid, newRow, newCol)) {
                    q.push({newRow, newCol});
                    compSum += grid[newRow][newCol];
                    compSize++;
                    grid[newRow][newCol] = -1;  // Mark as visited
                }
            }
        }
        // Return remoteness value for this component
        return (totalSum - compSum) * compSize;
    }

    // Checks if cell (row, col) is within grid bounds and not blocked/visited
    bool isValid(vector<vector<int>>& grid, int row, int col) {
        int n = grid.size();
        return row >= 0 && col >= 0 && row < n && col < n && grid[row][col] > 0;
    }
};
