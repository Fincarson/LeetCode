class Solution {
private:
    vector<vector<int>> triangle;
    map<pair<int, int>, int> memoTable;
    int minPath(int row, int col) {
        if (memoTable.count({row, col})) {
            return memoTable[{row, col}];
        }
        int path = triangle[row][col];
        if (row < triangle.size() - 1) {
            path += min(minPath(row + 1, col), minPath(row + 1, col + 1));
        }
        memoTable[{row, col}] = path;
        return path;
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        this->triangle = triangle;
        return minPath(0, 0);
    }
};
