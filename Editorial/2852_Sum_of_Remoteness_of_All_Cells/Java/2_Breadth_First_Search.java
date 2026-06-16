class Solution {

    // Direction arrays for moving up, down, left, right
    private final int[][] dir = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

    public long sumRemoteness(int[][] grid) {
        int n = grid.length;
        // Calculate total sum of all non-blocked cells
        long totalSum = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] != -1) {
                    totalSum += grid[row][col];
                }
            }
        }

        // Calculate remoteness for each non-blocked cell
        long result = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] > 0) {
                    result += bfs(grid, row, col, totalSum);
                }
            }
        }
        return result;
    }

    // BFS to find sum and count of all cells reachable from (row, col)
    private long bfs(int[][] grid, int row, int col, long totalSum) {
        long compSum = grid[row][col]; // Sum of values in current component
        long compSize = 1; // Number of cells in component
        grid[row][col] = -1; // Mark as visited

        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[] { row, col });

        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            // Explore all 4 directions
            for (int[] d : dir) {
                int newRow = d[0] + curr[0];
                int newCol = d[1] + curr[1];
                if (isValid(grid, newRow, newCol)) {
                    queue.add(new int[] { newRow, newCol });
                    compSum += grid[newRow][newCol];
                    compSize++;
                    grid[newRow][newCol] = -1; // Mark as visited
                }
            }
        }
        // Return remoteness value for this component
        return (totalSum - compSum) * compSize;
    }

    // Checks if cell (row, col) is within grid bounds and not blocked/visited
    private boolean isValid(int[][] grid, int row, int col) {
        int n = grid.length;
        return row >= 0 && col >= 0 && row < n && col < n && grid[row][col] > 0;
    }
}
