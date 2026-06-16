class Solution {
    // 4 directions to a cell's possible neighbors.
    vector<vector<int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        int left = 0, right = min(grid[0][0], grid[R - 1][C - 1]);
        while (left < right) {
            // Get the middle value between left and right boundaries.
            int middle = (left + right + 1) / 2;

            // Check if we can find a path of score equals middle, and cut the
            // search space by half.
            if (pathExists(grid, middle)) {
                left = middle;
            } else {
                right = middle - 1;
            }
        }

        // Once the left and right boundaries coincide, we find the target
        // value, that is, the maximum value of a path.
        return left;
    }

    // Check if we can find a path of value equals val.
    bool pathExists(vector<vector<int>>& grid, int val) {
        int R = grid.size(), C = grid[0].size();

        // Maintain the visited status of each cell. Initialize the status of
        // all the cells as false (unvisited).
        vector<vector<bool>> visited(R, vector<bool>(C, false));

        // Put the starting cell grid[0][0] in the deque and mark it as visited.
        visited[0][0] = true;
        deque<pair<int, int>> dq({{0, 0}});

        auto push = [&](int row, int col) {
            if (row == -1 || col == -1 || row == R || col == C ||
                visited[row][col] || grid[row][col] < val)
                return;
            dq.push_back({row, col});
            visited[row][col] = true;
        };

        // While we still have cells of value larger than or equal to val.
        while (!dq.empty()) {
            int curRow = dq.front().first, curCol = dq.front().second;
            dq.pop_front();

            // If the current cell is the bottom-right cell, return true.
            if (curRow == R - 1 && curCol == C - 1) return true;

            // Check if the current cell has any unvisited neighbors with value
            // larger than or equal to val. If so, we put this neighbor to the
            // deque and mark it as visited
            push(curRow + 1, curCol);
            push(curRow - 1, curCol);
            push(curRow, curCol + 1);
            push(curRow, curCol - 1);
        }
        return false;
    }
};
