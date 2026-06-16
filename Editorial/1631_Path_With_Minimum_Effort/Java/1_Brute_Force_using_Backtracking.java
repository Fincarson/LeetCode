class Solution {
    public int minimumEffortPath(int[][] heights) {
        return backtrack(0, 0, heights, heights.length, heights[0].length, 0);
    }

    int directions[][] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int maxSoFar = Integer.MAX_VALUE;

    int backtrack(int x, int y, int[][] heights, int row, int col, int maxDifference) {
        if (x == row - 1 && y == col - 1) {
            maxSoFar = Math.min(maxSoFar, maxDifference);
            return maxDifference;
        }
        int currentHeight = heights[x][y];
        heights[x][y] = 0;
        int minEffort = Integer.MAX_VALUE;
        for (int i = 0; i < 4; i++) {
            int adjacentX = x + directions[i][0];
            int adjacentY = y + directions[i][1];
            if (isValidCell(adjacentX, adjacentY, row, col) && heights[adjacentX][adjacentY] != 0) {
                int currentDifference = Math.abs(heights[adjacentX][adjacentY] - currentHeight);
                int maxCurrentDifference = Math.max(maxDifference, currentDifference);
                if (maxCurrentDifference < maxSoFar) {
                    int result = backtrack(adjacentX, adjacentY, heights, row, col, maxCurrentDifference);
                    minEffort = Math.min(minEffort, result);
                }
            }
        }
        heights[x][y] = currentHeight;
        return minEffort;
    }

    boolean isValidCell(int x, int y, int row, int col) {
        return x >= 0 && x <= row - 1 && y >= 0 && y <= col - 1;
    }
}
