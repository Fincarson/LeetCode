int largestRectangleArea(int* heights, int heightsSize) {
    int stack[heightsSize];
    int top = -1;
    int maxarea = 0;
    for (int i = 0; i <= heightsSize; ++i) {
        while (top != -1 &&
               (i == heightsSize || heights[stack[top]] >= heights[i])) {
            int height = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            int area = height * width;
            if (area > maxarea) maxarea = area;
        }
        stack[++top] = i;
    }
    return maxarea;
}
int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    int maxarea = 0;
    if (matrixSize == 0) return 0;
    int dp[matrixColSize[0]];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
        }
        maxarea = fmax(maxarea, largestRectangleArea(dp, matrixColSize[0]));
    }
    return maxarea;
}
