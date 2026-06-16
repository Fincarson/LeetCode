class Solution {

    private int R, C;

    // 4 directions to a cell's possible neighbors.
    private int[][] dirs = new int[][] {
        { 1, 0 },
        { -1, 0 },
        { 0, 1 },
        { 0, -1 },
    };

    public int maximumMinimumPath(int[][] grid) {
        R = grid.length;
        C = grid[0].length;
        int left = 0, right = Math.min(grid[0][0], grid[R - 1][C - 1]);
        while (left < right) {
            // Get the middle value between left and right boundaries.
            int middle = (right + left + 1) / 2;
            boolean[][] visited = new boolean[R][C];

            // Check if we can find a path with value = middle, and cut
            // the search space by half.
            if (pathExists(grid, middle, visited, 0, 0)) {
                left = middle;
            } else {
                right = middle - 1;
            }
        }

        // Once the left and right boundaries coincide, we find the target value,
        // that is, the maximum value of a path.
        return left;
    }

    // Check if we can find a path of value = val.
    private boolean pathExists(
        int[][] grid,
        int val,
        boolean[][] visited,
        int curRow,
        int curCol
    ) {
        // If we reach the bottom-right cell, return true.
        if (curRow == R - 1 && curCol == C - 1) return true;

        // Mark the current cell as visited.
        visited[curRow][curCol] = true;
        for (int[] dir : dirs) {
            int newRow = curRow + dir[0];
            int newCol = curCol + dir[1];

            // Check if the current cell has any unvisited neighbors with value larger
            // than or equal to val.
            if (
                newRow >= 0 &&
                newRow < R &&
                newCol >= 0 &&
                newCol < C &&
                !visited[newRow][newCol] &&
                grid[newRow][newCol] >= val
            ) {
                // If so, we continue search on this neighbor.
                if (pathExists(grid, val, visited, newRow, newCol)) return true;
            }
        }
        return false;
    }
}
