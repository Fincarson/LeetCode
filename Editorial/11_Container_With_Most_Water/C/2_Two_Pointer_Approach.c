int max(int a, int b) { return a > b ? a : b; }

int min(int a, int b) { return a < b ? a : b; }

int maxArea(int* height, int heightSize) {
    int maxArea = 0;
    int left = 0;
    int right = heightSize - 1;

    while (left < right) {
        int width = right - left;
        maxArea = max(maxArea, min(height[left], height[right]) * width);
        if (height[left] <= height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxArea;
}
