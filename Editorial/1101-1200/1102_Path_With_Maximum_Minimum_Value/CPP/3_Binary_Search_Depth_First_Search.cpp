class Solution {
private:
    int R, C;
    bool visited[101][101];

    // 4 directions to a cell's possible neighbors.
    vector<vector<int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        R = grid.size();
        C = grid[0].size();

        // Initialize the two boundaries of the search space.
        int left = 0, right = min(grid[0][0], grid[R - 1][C - 1]);

        while (left < right) {
            // Get the middle value between left and right boundaries.
            int middle = (left + right + 1) >> 1;
            memset(visited, false, sizeof(visited));

            // Check if we can find a path having value equals middle, and cut
            // the search space by half.
            if (pathExists(grid, middle, 0, 0)) {
                left = middle;
            } else {
                right = middle - 1;
            }
        }

        // Once the left and right boundaries coincide, we find the target
        // value, that is, the maximum value of a path.
        return left;
    }

    // Check if we can find a path of value = val.
    int pathExists(vector<vector<int>>& grid, int val, int curRow, int curCol) {
        // If we reach the bottom-right cell, return true.
        if (curRow == R - 1 && curCol == C - 1) return true;

        // Mark the current cell as visited.
        visited[curRow][curCol] = true;
        for (vector<int> dir : dirs) {
            int newRow = curRow + dir[0];
            int newCol = curCol + dir[1];

            // Check if the current cell has any unvisited neighbors with value
            // larger than or equal to val.
            if (newRow >= 0 && newRow < R && newCol >= 0 && newCol < C &&
                !visited[newRow][newCol] && grid[newRow][newCol] >= val) {
                // If so, we continue search on this neighbor.
                if (pathExists(grid, val, newRow, newCol)) return true;
            }
        }
        return false;
    }
};
