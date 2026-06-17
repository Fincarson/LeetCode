class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {

        // Repeat the transform k times.
        for (;k > 0; k--) {
            // We'll write the transform into a new 2D array.
            int[][] newGrid = new int[grid.length][grid[0].length];

            // Case #1: Move everything not in the last column.
            for (int row = 0; row < grid.length; row++) {
                for (int col = 0; col < grid[0].length - 1; col++) {
                    newGrid[row][col + 1] = grid[row][col];
                }
            }

            // Case #2: Move everything in last column, but not last row.
            for (int row = 0; row < grid.length - 1; row++) {
                newGrid[row + 1][0] = grid[row][grid[0].length - 1];
            }

            // Case #3: Move the bottom right.
            newGrid[0][0] = grid[grid.length - 1][grid[0].length - 1];

            // Update grid to be the transformed grid.
            grid = newGrid;
        }

        // Copy the grid into a list for returning.
        List<List<Integer>> result = new ArrayList<>();
        for (int[] row : grid) {
            List<Integer> listRow = new ArrayList<>();
            result.add(listRow);
            for (int v : row) listRow.add(v);
        }

        return result;
    }
}
