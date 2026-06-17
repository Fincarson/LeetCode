class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        // Store the matrix dimensions.
        size_t m = mat.size();
        size_t n = mat[0].size();

        // Sort each diagonal that starts on a row.
        for (size_t row = 0; row < m; row++) {
            sortDiagonal(row, 0, mat);
        }

        // Sort each diagonal that starts on a col.
        // Note that we've already sorted the one starting
        // at col = 0; this is the same as the one starting
        // at row = 0.
        for (size_t col = 0; col < n; col++) {
            sortDiagonal(0, col, mat);
        }

        return mat;
    }

    // Helper function to sort the current diagonal at row, col
    void sortDiagonal(size_t row, size_t col, vector<vector<int>>& mat) {
        size_t m = mat.size();
        size_t n = mat[0].size();

        // create a min-heap to store the diagonal
        priority_queue<int, vector<int>, greater<int>> diagonal;

        size_t diagonal_length = min(m - row, n - col);
        // Put values on this diagonal into the heap.
        for (size_t i = 0; i < diagonal_length; i++) {
            diagonal.push(mat[row + i][col + i]);
        }

        // Put values on heap back into this diagonal
        for (size_t i = 0; i < diagonal_length; i++) {
            mat[row + i][col + i] = diagonal.top();
            diagonal.pop();
        }
    }
};
