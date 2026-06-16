class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int N = 9;
        // Use vectors to record the status
        vector<vector<int>> rows(N, vector<int>(N, 0));
        vector<vector<int>> cols(N, vector<int>(N, 0));
        vector<vector<int>> boxes(N, vector<int>(N, 0));
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                // Check if the position is filled with number
                if (board[r][c] == '.') {
                    continue;
                }
                int pos = board[r][c] - '1';
                // Check the row
                if (rows[r][pos] == 1) {
                    return false;
                }
                rows[r][pos] = 1;
                // Check the column
                if (cols[c][pos] == 1) {
                    return false;
                }
                cols[c][pos] = 1;
                // Check the box
                int idx = (r / 3) * 3 + c / 3;
                if (boxes[idx][pos] == 1) {
                    return false;
                }
                boxes[idx][pos] = 1;
            }
        }
        return true;
    }
};
