class Solution {
public:
    int leetcode84(vector<int>& heights) {
        vector<int> stack = {-1};
        int maxarea = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (stack.back() != -1 && heights[stack.back()] >= heights[i]) {
                int height = heights[stack.back()];
                stack.pop_back();
                maxarea = max(maxarea, height * (i - stack.back() - 1));
            }
            stack.push_back(i);
        }
        while (stack.back() != -1) {
            int height = heights[stack.back()];
            stack.pop_back();
            maxarea = max(maxarea, height * (static_cast<int>(heights.size()) -
                                             stack.back() - 1));
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int maxarea = 0;
        vector<int> dp(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                // update the state of this row's histogram using the last row's
                // histogram by keeping track of the number of consecutive ones
                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
            }
            // update maxarea with the maximum area from this row's histogram
            maxarea = max(maxarea, leetcode84(dp));
        }
        return maxarea;
    }
};
