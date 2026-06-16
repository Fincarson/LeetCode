int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize,
                 int* returnSize) {
    *returnSize = matrixSize * (*matrixColSize);
    int* result = (int*)malloc(sizeof(int) * (*returnSize));
    int idx = 0;
    int rows = matrixSize;
    int columns = *matrixColSize;
    int up = 0;
    int left = 0;
    int right = columns - 1;
    int down = rows - 1;
    while (idx < *returnSize) {
        // Traverse from left to right.
        for (int col = left; col <= right; col++) {
            result[idx++] = matrix[up][col];
        }
        // Traverse downwards.
        for (int row = up + 1; row <= down; row++) {
            result[idx++] = matrix[row][right];
        }
        // Make sure we are now on a different row.
        if (up != down) {
            // Traverse from right to left.
            for (int col = right - 1; col >= left; col--) {
                result[idx++] = matrix[down][col];
            }
        }
        // Make sure we are now on a different column.
        if (left != right) {
            // Traverse upwards.
            for (int row = down - 1; row > up; row--) {
                result[idx++] = matrix[row][left];
            }
        }
        left++;
        right--;
        up++;
        down--;
    }
    return result;
}
