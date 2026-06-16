class Solution {

    public int countServers(int[][] grid) {
        int communicableServersCount = 0;
        int[] colCount = new int[grid[0].length];
        int[] lastServerInRow = new int[grid.length];
        for (int i = 0; i < lastServerInRow.length; i++) {
            lastServerInRow[i] = -1;
        }

        // First pass to count servers in each row and column
        for (int row = 0; row < grid.length; row++) {
            int serverCountInRow = 0;
            for (int col = 0; col < grid[0].length; col++) {
                if (grid[row][col] == 1) {
                    serverCountInRow++;
                    colCount[col]++;
                    lastServerInRow[row] = col;
                }
            }
            // If there is more than one server in the row, increase the count
            if (serverCountInRow != 1) {
                communicableServersCount += serverCountInRow;
                lastServerInRow[row] = -1;
            }
        }

        // Second pass to check if servers can communicate
        for (int row = 0; row < grid.length; row++) {
            if (
                lastServerInRow[row] != -1 &&
                colCount[lastServerInRow[row]] > 1
            ) {
                communicableServersCount++;
            }
        }

        return communicableServersCount;
    }
}
