int numberOfSubmatrices(char** grid, int gridSize, int* gridColSize) {
    int n = gridSize, m = gridColSize[0];
    int ans = 0;
    int sum[n + 1][m + 1][2];

    memset(sum, 0, sizeof(sum));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'X') {
                sum[i + 1][j + 1][0] =
                    sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0] + 1;
                sum[i + 1][j + 1][1] = 1;
            } else if (grid[i][j] == 'Y') {
                sum[i + 1][j + 1][0] =
                    sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0] - 1;
                sum[i + 1][j + 1][1] = sum[i + 1][j][1] | sum[i][j + 1][1];
            } else {
                sum[i + 1][j + 1][0] =
                    sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0];
                sum[i + 1][j + 1][1] = sum[i + 1][j][1] | sum[i][j + 1][1];
            }
            if (sum[i + 1][j + 1][0] == 0 && sum[i + 1][j + 1][1] == 1) {
                ans++;
            }
        }
    }
    return ans;
}
