class Solution {

    public int[][] minScore(int[][] grid) {
        // Get size of the grid
        int rowSize = grid.length, colSize = grid[0].length;

        // Initialize PriorityQueue to store elements with their values and coordinates
        PriorityQueue<int[]> min_heap = new PriorityQueue<>(
            (a, b) -> a[0] - b[0]
        );

        // Initialize arrays to keep track of maximum values assigned
        int[] rows = new int[rowSize];
        int[] cols = new int[colSize];
        for (int i = 0; i < rowSize; i++) rows[i] = 1;
        for (int j = 0; j < colSize; j++) cols[j] = 1;

        // Populate the heap with all elements of the grid
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                min_heap.offer(new int[] { grid[i][j], i, j });
            }
        }

        // Process elements in ascending order of their values
        while (!min_heap.isEmpty()) {
            int[] element = min_heap.poll();
            int value = element[0];
            int row = element[1];
            int col = element[2];

            // Determine the smallest assignable value based on rows and cols constraints
            int val = Math.max(rows[row], cols[col]);
            grid[row][col] = val;

            // Update rows and cols arrays with the next possible value for each row and column
            rows[row] = val + 1;
            cols[col] = val + 1;
        }

        return grid;
    }
}
