class Solution {
public:
    int getNum(int row, int col) {
        if (row == 0 || col == 0 || row == col) return 1;

        return getNum(row - 1, col - 1) + getNum(row - 1, col);
    }

    vector<int> getRow(int rowIndex) {
        vector<int> ans;

        for (int i = 0; i <= rowIndex; i++) ans.push_back(getNum(rowIndex, i));

        return ans;
    }
};
