class Solution {

    public int[] maxPoints(int[][] grid, int[] queries) {
        int rowCount = grid.length, colCount = grid[0].length;
        int[] result = new int[queries.length];
        // Directions for moving in 4 directions (right, down, left, up)
        int[][] DIRECTIONS = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

        // Iterate through each query value
        for (int queryIndex = 0; queryIndex < queries.length; queryIndex++) {
            int queryValue = queries[queryIndex];
            Queue<int[]> bfsQueue = new LinkedList<>();
            // Start BFS from the top-left corner
            bfsQueue.add(new int[] { 0, 0 });
            boolean[][] visited = new boolean[rowCount][colCount];
            // Mark the starting cell as visited
            visited[0][0] = true;
            int points = 0;

            // BFS traversal
            while (!bfsQueue.isEmpty()) {
                int queueSize = bfsQueue.size();
                for (int i = 0; i < queueSize; i++) {
                    int[] current = bfsQueue.poll();
                    int currentRow = current[0];
                    int currentCol = current[1];

                    // If the current cell's value is greater than or equal to
                    // queryValue, stop expanding from here
                    if (grid[currentRow][currentCol] >= queryValue) continue;

                    // Count the valid cell
                    points++;

                    // Explore all four possible directions
                    for (int[] direction : DIRECTIONS) {
                        int newRow = currentRow + direction[0];
                        int newCol = currentCol + direction[1];

                        // Ensure the new position is within bounds and has not
                        // been visited
                        if (
                            newRow >= 0 &&
                            newCol >= 0 &&
                            newRow < rowCount &&
                            newCol < colCount &&
                            !visited[newRow][newCol] &&
                            grid[newRow][newCol] < queryValue
                        ) {
                            bfsQueue.add(new int[] { newRow, newCol });
                            // Mark the new cell as visited
                            visited[newRow][newCol] = true;
                        }
                    }
                }
            }
            // Store the result for the current query
            result[queryIndex] = points;
        }
        return result;
    }
}
