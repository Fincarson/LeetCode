class Solution {
private:
    int ROWS;
    int COLS;
    void BFS(vector<vector<char>>& board, int row, int col) {
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        while (q.size() > 0) {
            auto front = q.front();
            int row = front.first, col = front.second;
            q.pop();
            if (board[row][col] != 'O') continue;
            board[row][col] = 'E';
            if (col < COLS - 1) q.push(make_pair(row, col + 1));
            if (row < ROWS - 1) q.push(make_pair(row + 1, col));
            if (col > 0) q.push(make_pair(row, col - 1));
            if (row > 0) q.push(make_pair(row - 1, col));
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int numRows = board.size();
        if (numRows == 0) return;
        int numCols = board[0].size();
        this->ROWS = numRows;
        this->COLS = numCols;
        vector<pair<int, int>> border;
        for (int r = 0; r < this->ROWS; ++r) {
            border.push_back(make_pair(r, 0));
            border.push_back(make_pair(r, this->COLS - 1));
        }
        for (int c = 0; c < this->COLS; ++c) {
            border.push_back(make_pair(0, c));
            border.push_back(make_pair(this->ROWS - 1, c));
        }
        for (pair<int, int> border_pair : border)
            this->BFS(board, border_pair.first, border_pair.second);
        for (int r = 0; r < this->ROWS; ++r) {
            for (int c = 0; c < this->COLS; ++c) {
                if (board[r][c] == 'O') board[r][c] = 'X';
                if (board[r][c] == 'E') board[r][c] = 'O';
            }
        }
    }
};
