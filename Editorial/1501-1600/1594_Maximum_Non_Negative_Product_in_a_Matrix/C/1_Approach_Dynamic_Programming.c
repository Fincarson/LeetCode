#define MOD 1000000007

int maxProductPath(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    long long** maxgt = (long long**)malloc(m * sizeof(long long*));
    long long** minlt = (long long**)malloc(m * sizeof(long long*));
    for (int i = 0; i < m; i++) {
        maxgt[i] = (long long*)malloc(n * sizeof(long long));
        minlt[i] = (long long*)malloc(n * sizeof(long long));
    }

    maxgt[0][0] = minlt[0][0] = grid[0][0];
    for (int i = 1; i < n; i++) {
        maxgt[0][i] = minlt[0][i] = maxgt[0][i - 1] * grid[0][i];
    }
    for (int i = 1; i < m; i++) {
        maxgt[i][0] = minlt[i][0] = maxgt[i - 1][0] * grid[i][0];
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] >= 0) {
                maxgt[i][j] =
                    fmax(maxgt[i][j - 1], maxgt[i - 1][j]) * grid[i][j];
                minlt[i][j] =
                    fmin(minlt[i][j - 1], minlt[i - 1][j]) * grid[i][j];
            } else {
                maxgt[i][j] =
                    fmin(minlt[i][j - 1], minlt[i - 1][j]) * grid[i][j];
                minlt[i][j] =
                    fmax(maxgt[i][j - 1], maxgt[i - 1][j]) * grid[i][j];
            }
        }
    }

    long long result = maxgt[m - 1][n - 1];
    for (int i = 0; i < m; i++) {
        free(maxgt[i]);
        free(minlt[i]);
    }
    free(maxgt);
    free(minlt);

    if (result < 0) {
        return -1;
    } else {
        return result % MOD;
    }
}
