int largestRectangleArea(int* heights, int heightsSize) {
    int* stack = (int*)malloc((heightsSize + 1) * sizeof(int));
    int top = -1;
    stack[++top] = -1;
    int maxArea = 0;
    for (int i = 0; i < heightsSize; i++) {
        while (top != 0 && heights[stack[top]] >= heights[i]) {
            int currentHeight = heights[stack[top--]];
            int currentWidth = i - stack[top] - 1;
            maxArea = (currentHeight * currentWidth > maxArea)
                          ? currentHeight * currentWidth
                          : maxArea;
        }
        stack[++top] = i;
    }
    while (top != 0) {
        int currentHeight = heights[stack[top--]];
        int currentWidth = heightsSize - stack[top] - 1;
        maxArea = (currentHeight * currentWidth > maxArea)
                      ? currentHeight * currentWidth
                      : maxArea;
    }
    free(stack);
    return maxArea;
}
