int** rangeAddQueries(int n, int** queries, int queriesSize,
                      int* queriesColSize, int* returnSize,
                      int** returnColumnSizes) {
    int diff[n + 1][n + 1] = {};
    for (int k = 0; k < queriesSize; k++) {
        int row1 = queries[k][0], col1 = queries[k][1], row2 = queries[k][2],
            col2 = queries[k][3];
        diff[row1][col1] += 1;
        diff[row2 + 1][col1] -= 1;
        diff[row1][col2 + 1] -= 1;
        diff[row2 + 1][col2 + 1] += 1;
    }

    int** mat = (int**)malloc(n * sizeof(int*));
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        mat[i] = (int*)calloc(n, sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
    *returnSize = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x1 = (i == 0) ? 0 : mat[i - 1][j];
            int x2 = (j == 0) ? 0 : mat[i][j - 1];
            int x3 = (i == 0 || j == 0) ? 0 : mat[i - 1][j - 1];
            mat[i][j] = diff[i][j] + x1 + x2 - x3;
        }
    }
    return mat;
}
