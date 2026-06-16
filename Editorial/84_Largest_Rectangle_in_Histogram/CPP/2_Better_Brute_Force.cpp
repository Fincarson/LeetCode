class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        size_t max_area = 0;
        for (size_t i = 0; i < heights.size(); i++) {
            int min_height = INT_MAX;
            for (size_t j = i; j < heights.size(); j++) {
                min_height = min(min_height, heights[j]);
                max_area = max(max_area, min_height * (j - i + 1));
            }
        }
        return max_area;
    }
};
