class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int row = triangle.size() - 2; row >= 0; --row) {
            for (int col = 0; col <= row; ++col) {
                int bestBelow = std::min(triangle[row + 1][col],
                                         triangle[row + 1][col + 1]);
                triangle[row][col] += bestBelow;
            }
        }
        return triangle[0][0];
    }
};
