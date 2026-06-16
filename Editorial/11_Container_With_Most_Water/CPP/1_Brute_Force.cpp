class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        for (int left = 0; left < height.size(); left++) {
            for (int right = left + 1; right < height.size(); right++) {
                int width = right - left;
                maxarea = max(maxarea, min(height[left], height[right]) * width);
            }
        }
        return maxarea;
    }
};
