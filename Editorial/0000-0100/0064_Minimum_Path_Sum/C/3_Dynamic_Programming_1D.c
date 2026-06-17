int minPathSum(int** grid, int gridRowSize, int* gridColSizes) {
    int* dp = (int*)malloc(sizeof(int) * gridColSizes[0]);
    for (int i = gridRowSize - 1; i >= 0; i--) {
        for (int j = gridColSizes[0] - 1; j >= 0; j--) {
            if (i == gridRowSize - 1 && j != gridColSizes[0] - 1)
                dp[j] = grid[i][j] + dp[j + 1];
            else if (j == gridColSizes[0] - 1 && i != gridRowSize - 1)
                dp[j] = grid[i][j] + dp[j];
            else if (j != gridColSizes[0] - 1 && i != gridRowSize - 1)
                dp[j] = grid[i][j] + (dp[j] < dp[j + 1] ? dp[j] : dp[j + 1]);
            else
                dp[j] = grid[i][j];
        }
    }
    int result = dp[0];
    free(dp);
    return result;
}
