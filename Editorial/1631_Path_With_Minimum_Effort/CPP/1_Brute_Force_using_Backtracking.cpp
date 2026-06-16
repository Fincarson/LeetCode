class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        return backtrack(0, 0, heights, heights.size(), heights[0].size(), 0);
    }

    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int maxSoFar = INT_MAX;

    int backtrack(int x, int y, vector<vector<int>> &heights, int row, int col,
                  int maxDifference) {
        if (x == row - 1 && y == col - 1) {
            maxSoFar = min(maxSoFar, maxDifference);
            return maxDifference;
        }
        int currentHeight = heights[x][y];
        heights[x][y] = 0;
        int minEffort = INT_MAX;
        for (int i = 0; i < 4; i++) {
            int adjacentX = x + directions[i][0];
            int adjacentY = y + directions[i][1];
            if (isValidCell(adjacentX, adjacentY, row, col) &&
                heights[adjacentX][adjacentY] != 0) {
                int currentDifference =
                    abs(heights[adjacentX][adjacentY] - currentHeight);
                int maxCurrentDifference =
                    max(maxDifference, currentDifference);
                if (maxCurrentDifference < maxSoFar) {
                    int result = backtrack(adjacentX, adjacentY, heights, row,
                                           col, maxCurrentDifference);
                    minEffort = min(minEffort, result);
                }
            }
        }
        heights[x][y] = currentHeight;
        return minEffort;
    }

    bool isValidCell(int x, int y, int row, int col) {
        return x >= 0 && x <= row - 1 && y >= 0 && y <= col - 1;
    }
};
