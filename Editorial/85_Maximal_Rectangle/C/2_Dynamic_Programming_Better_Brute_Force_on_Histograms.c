int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0) return 0;
    int maxarea = 0;
    int dp[matrixSize][*matrixColSize];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            if (matrix[i][j] == '1') {
                // compute the maximum width and update dp with it
                dp[i][j] = j == 0 ? 1 : dp[i][j - 1] + 1;
                int width = dp[i][j];
                // compute the maximum area rectangle with a lower right corner
                // at [i, j]
                for (int k = i; k >= 0; k--) {
                    width = width < dp[k][j] ? width : dp[k][j];
                    maxarea = maxarea > (width * (i - k + 1))
                                  ? maxarea
                                  : (width * (i - k + 1));
                }
            }
        }
    }
    return maxarea;
}
