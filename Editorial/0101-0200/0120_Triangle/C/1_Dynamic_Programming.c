int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    for (int row = 1; row < triangleSize; ++row) {
        for (int col = 0; col <= row; ++col) {
            int smallestAbove = INT_MAX;
            if (col > 0) {
                smallestAbove = triangle[row - 1][col - 1];
            }
            if (col < row) {
                smallestAbove = fmin(smallestAbove, triangle[row - 1][col]);
            }
            triangle[row][col] += smallestAbove;
        }
    }
    int min_val = triangle[triangleSize - 1][0];
    for (int i = 0; i < triangleColSize[triangleSize - 1]; i++) {
        if (triangle[triangleSize - 1][i] < min_val) {
            min_val = triangle[triangleSize - 1][i];
        }
    }
    return min_val;
}
