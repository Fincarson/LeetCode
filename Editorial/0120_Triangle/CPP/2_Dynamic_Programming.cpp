class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> prevRow = triangle[0];
        for (int row = 1; row < triangle.size(); row++) {
            vector<int> currRow;
            for (int col = 0; col <= row; col++) {
                int smallestAbove = INT_MAX;
                if (col > 0) {
                    smallestAbove = prevRow[col - 1];
                }
                if (col < row) {
                    smallestAbove = min(smallestAbove, prevRow[col]);
                }
                currRow.push_back(smallestAbove + triangle[row][col]);
            }
            prevRow = currRow;
        }
        return *min_element(prevRow.begin(), prevRow.end());
    }
};
