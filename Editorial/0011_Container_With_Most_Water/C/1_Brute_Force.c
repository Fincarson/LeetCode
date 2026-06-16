int max(int a, int b) { return a > b ? a : b; }

int min(int a, int b) { return a < b ? a : b; }

int maxArea(int* height, int heightSize) {
    int maxarea = 0;

    for (int left = 0; left < heightSize; left++) {
        for (int right = left + 1; right < heightSize; right++) {
            int width = right - left;
            maxarea = max(maxarea, min(height[left], height[right]) * width);
        }
    }

    return maxarea;
}
