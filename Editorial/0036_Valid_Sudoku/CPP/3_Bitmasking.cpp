class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int N = 9;
        // Use a binary number to record previous occurrence
        int rows[N] = {0};
        int cols[N] = {0};
        int boxes[N] = {0};
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                // Check if the position is filled with number
                if (board[r][c] == '.') {
                    continue;
                }
                int val = board[r][c] - '0';
                int pos = 1 << (val - 1);
                // Check the row
                if ((rows[r] & pos) > 0) {
                    return false;
                }
                rows[r] |= pos;
                // Check the column
                if ((cols[c] & pos) > 0) {
                    return false;
                }
                cols[c] |= pos;
                // Check the box
                int idx = (r / 3) * 3 + c / 3;
                if ((boxes[idx] & pos) > 0) {
                    return false;
                }
                boxes[idx] |= pos;
            }
        }
        return true;
    }
};
