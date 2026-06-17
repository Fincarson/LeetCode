class Solution {

    // Possible knight moves: (row, column) pairs
    int[][] knightMoves = {
        { -1, -2 },
        { -2, -1 },
        { -1, 2 },
        { -2, 1 },
        { 1, -2 },
        { 2, -1 },
        { 1, 2 },
        { 2, 1 },
    };

    public int[][] tourOfKnight(int m, int n, int r, int c) {
        int[][] chessboard = new int[m][n];
        chessboard[r][c] = -1;

        solveKnightsTour(m, n, r, c, chessboard, 1);

        // Reset starting position to 0
        chessboard[r][c] = 0;
        return chessboard;
    }

    private boolean solveKnightsTour(
        int rows,
        int cols,
        int currentRow,
        int currentCol,
        int[][] chessboard,
        int moveCount
    ) {
        // Base case: if all cells are visited, we've found a solution
        if (moveCount == rows * cols) return true;

        // Get and sort possible next moves based on Warnsdorff's rule
        List<int[]> nextMoves = getNextMovesWarnsdorff(
            chessboard,
            currentRow,
            currentCol
        );

        // Try each possible move
        for (int[] move : nextMoves) {
            int nextRow = currentRow + knightMoves[move[1]][0];
            int nextCol = currentCol + knightMoves[move[1]][1];

            if (!isValidMove(chessboard, nextRow, nextCol)) continue;

            chessboard[nextRow][nextCol] = moveCount;

            // Recursively try to solve from this new position
            if (
                solveKnightsTour(
                    rows,
                    cols,
                    nextRow,
                    nextCol,
                    chessboard,
                    moveCount + 1
                )
            ) {
                return true;
            }

            // If the move doesn't lead to a solution, backtrack
            chessboard[nextRow][nextCol] = 0;
        }

        return false; // No solution found from this position
    }

    // Implement Warnsdorff's rule: prefer moves with fewer onward moves
    private List<int[]> getNextMovesWarnsdorff(
        int[][] chessboard,
        int row,
        int col
    ) {
        List<int[]> nextMoves = new ArrayList<>();
        for (int moveIndex = 0; moveIndex < 8; moveIndex++) {
            int nextRow = row + knightMoves[moveIndex][0];
            int nextCol = col + knightMoves[moveIndex][1];
            int accessibilityScore = countAccessibleMoves(
                chessboard,
                nextRow,
                nextCol
            );
            nextMoves.add(new int[] { accessibilityScore, moveIndex });
        }
        // Sort moves based on accessibility (fewer accessible squares first)
        Collections.sort(nextMoves, (a, b) -> a[0] - b[0]);
        return nextMoves;
    }

    private int countAccessibleMoves(int[][] chessboard, int row, int col) {
        int count = 0;
        for (int[] move : knightMoves) {
            int nextRow = row + move[0];
            int nextCol = col + move[1];
            if (isValidMove(chessboard, nextRow, nextCol)) count++;
        }
        return count;
    }

    private boolean isValidMove(int[][] chessboard, int row, int col) {
        return (
            row >= 0 &&
            col >= 0 &&
            row < chessboard.length &&
            col < chessboard[0].length &&
            chessboard[row][col] == 0
        );
    }
}
