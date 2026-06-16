class Solution {
public:
    vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {
        vector<vector<int>> chessboard(m, vector<int>(n, 0));
        chessboard[r][c] = -1;

        solveKnightsTour(m, n, r, c, chessboard, 1);

        // Reset starting position to 0
        chessboard[r][c] = 0;
        return chessboard;
    }

private:
    // Possible knight moves: (row, column) pairs
    int knightMoves[8][2] = {{-1, -2}, {-2, -1}, {-1, 2}, {-2, 1},
                             {1, -2},  {2, -1},  {1, 2},  {2, 1}};

    bool solveKnightsTour(int rows, int cols, int currentRow, int currentCol,
                          vector<vector<int>>& chessboard, int moveCount) {
        // Base case: if all cells are visited, we've found a solution
        if (moveCount == rows * cols) return true;

        // Get and sort possible next moves based on Warnsdorff's rule
        vector<pair<int, int>> nextMoves =
            getNextMovesWarnsdorff(chessboard, currentRow, currentCol);

        // Try each possible move
        for (auto& move : nextMoves) {
            int nextRow = currentRow + knightMoves[move.second][0];
            int nextCol = currentCol + knightMoves[move.second][1];

            if (!isValidMove(chessboard, nextRow, nextCol)) continue;

            chessboard[nextRow][nextCol] = moveCount;

            // Recursively try to solve from this new position
            if (solveKnightsTour(rows, cols, nextRow, nextCol, chessboard,
                                 moveCount + 1)) {
                return true;
            }

            // If the move doesn't lead to a solution, backtrack
            chessboard[nextRow][nextCol] = 0;
        }

        return false;  // No solution found from this position
    }

    // Implement Warnsdorff's rule: prefer moves with fewer onward moves
    vector<pair<int, int>> getNextMovesWarnsdorff(
        vector<vector<int>>& chessboard, int row, int col) {
        vector<pair<int, int>> nextMoves;
        for (int moveIndex = 0; moveIndex < 8; moveIndex++) {
            int nextRow = row + knightMoves[moveIndex][0];
            int nextCol = col + knightMoves[moveIndex][1];
            int accessibilityScore =
                countAccessibleMoves(chessboard, nextRow, nextCol);
            nextMoves.push_back({accessibilityScore, moveIndex});
        }
        // Sort moves based on accessibility (fewer accessible squares first)
        sort(nextMoves.begin(), nextMoves.end());
        return nextMoves;
    }

    int countAccessibleMoves(vector<vector<int>>& chessboard, int row,
                             int col) {
        int count = 0;
        for (int i = 0; i < 8; i++) {
            int nextRow = row + knightMoves[i][0];
            int nextCol = col + knightMoves[i][1];
            if (isValidMove(chessboard, nextRow, nextCol)) count++;
        }
        return count;
    }

    bool isValidMove(vector<vector<int>>& chessboard, int row, int col) {
        return row >= 0 && col >= 0 && row < chessboard.size() &&
               col < chessboard[0].size() && chessboard[row][col] == 0;
    }
};
