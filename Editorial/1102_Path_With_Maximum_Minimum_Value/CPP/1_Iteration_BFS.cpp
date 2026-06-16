class Solution {
    // 4 directions to a cell's possible neighbors.
    vector<vector<int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        int curScore = min(grid[0][0], grid[R - 1][C - 1]);

        // Start with "curScore", check if we can find a path having score
        // equals "curScore". If so, return curScore as the maximum score,
        // otherwise, decrease curScore by 1 and repeat these steps.
        while (curScore >= 0) {
            if (pathExists(grid, curScore)) {
                return curScore;
            } else {
                curScore = curScore - 1;
            }
        }
        return -1;
    }

    // Check if we can find a path of score equals curScore.
    bool pathExists(vector<vector<int>>& grid, int curScore) {
        int R = grid.size(), C = grid[0].size();
        // Maintain the visited status of each cell. Initialize the status of
        // all the cells as false (unvisited).
        vector<vector<bool>> visited(R, vector<bool>(C, false));

        // Put the starting cell grid[0][0] in the deque and mark it as visited.
        visited[0][0] = true;
        deque<pair<int, int>> dq({{0, 0}});

        auto push = [&](int row, int col) {
            if (row == -1 || col == -1 || row == R || col == C ||
                visited[row][col] || grid[row][col] < curScore)
                return;
            dq.push_back({row, col});
            visited[row][col] = true;
        };

        // While we still have cells of value larger than or equal to curScore.
        while (!dq.empty()) {
            int curRow = dq.front().first, curCol = dq.front().second;
            dq.pop_front();

            // If the current cell is the bottom-right cell, return true.
            if (curRow == R - 1 && curCol == C - 1) {
                return true;
            }

            // Check if the current cell has any unvisited neighbors with value
            // larger than or equal to curScore. If so, we put this neighbor to
            // the deque and mark it as visited
            push(curRow + 1, curCol);
            push(curRow - 1, curCol);
            push(curRow, curCol + 1);
            push(curRow, curCol - 1);
        }
        return false;
    }
};
