class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int maxarea = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    // compute the maximum width and update dp with it
                    dp[i][j] = j == 0 ? 1 : dp[i][j - 1] + 1;
                    int width = dp[i][j];
                    // compute the maximum area rectangle with a lower right
                    // corner at [i, j]
                    for (int k = i; k >= 0; k--) {
                        width = std::min(width, dp[k][j]);
                        maxarea = std::max(maxarea, width * (i - k + 1));
                    }
                }
            }
        }
        return maxarea;
    }
};
