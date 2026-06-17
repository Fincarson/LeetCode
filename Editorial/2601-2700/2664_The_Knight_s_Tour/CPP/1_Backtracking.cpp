class Solution {
public:
    vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {
        vector<vector<int>> chessboard(m, vector<int>(n, 0));

        chessboard[r][c] = -1;

        // Start the recursive solving process
        solveKnightsTour(m, n, r, c, chessboard, 1);

        chessboard[r][c] = 0;

        return chessboard;
    }

private:
    bool solveKnightsTour(int rows, int cols, int currentRow, int currentCol,
                          vector<vector<int>>& chessboard, int moveCount) {
        // Base case: if all cells have been visited, we've found a solution
        if (moveCount == rows * cols) {
            return true;
        }

        // Try all possible knight moves
        for (int newRow = 0; newRow < rows; newRow++) {
            for (int newCol = 0; newCol < cols; newCol++) {
                // Check if the move is valid
                if (!isValidMove(chessboard, currentRow, currentCol, newRow,
                                 newCol)) {
                    continue;
                }

                chessboard[newRow][newCol] = moveCount;

                // Recursively try to solve from this new position
                if (solveKnightsTour(rows, cols, newRow, newCol, chessboard,
                                     moveCount + 1)) {
                    return true;
                }

                // If the move doesn't lead to a solution, backtrack
                chessboard[newRow][newCol] = 0;
            }
        }

        // If no solution is found from the current position
        return false;
    }

    bool isValidMove(const vector<vector<int>>& chessboard, int fromRow,
                     int fromCol, int toRow, int toCol) {
        return toRow >= 0 && toCol >= 0 && toRow < chessboard.size() &&
               toCol < chessboard[0].size() &&
               min(abs(fromRow - toRow), abs(fromCol - toCol)) == 1 &&
               max(abs(fromRow - toRow), abs(fromCol - toCol)) == 2 &&
               chessboard[toRow][toCol] == 0;
    }
};
