void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int R = matrixSize;
    int C = *matrixColSize;
    int rows[R], cols[C];
    memset(rows, 0, sizeof(rows));
    memset(cols, 0, sizeof(cols));
    // Essentially, we mark the rows and columns that are to be made zero
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (matrix[i][j] == 0) {
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }
    // Iterate over the array once again and using the rows and cols sets,
    // update the elements
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (rows[i] == 1 || cols[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
}
