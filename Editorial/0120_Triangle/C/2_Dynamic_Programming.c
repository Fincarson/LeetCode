int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int* prevRow = malloc(triangleColSize[0] * sizeof(int));
    for (int i = 0; i < triangleColSize[0]; i++) {
        prevRow[i] = triangle[0][i];
    }
    for (int row = 1; row < triangleSize; row++) {
        int* currRow = malloc(triangleColSize[row] * sizeof(int));
        for (int col = 0; col <= row; col++) {
            int smallestAbove = INT_MAX;
            if (col > 0) {
                smallestAbove = prevRow[col - 1];
            }
            if (col < row) {
                smallestAbove = (smallestAbove < prevRow[col]) ? smallestAbove
                                                               : prevRow[col];
            }
            currRow[col] = smallestAbove + triangle[row][col];
        }
        free(prevRow);
        prevRow = currRow;
    }
    int minVal = INT_MAX;
    for (int i = 0; i < triangleSize; i++) {
        minVal = (minVal < prevRow[i]) ? minVal : prevRow[i];
    }
    free(prevRow);
    return minVal;
}
