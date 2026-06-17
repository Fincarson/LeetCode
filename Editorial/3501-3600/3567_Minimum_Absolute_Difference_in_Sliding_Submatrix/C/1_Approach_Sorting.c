int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int** minAbsDiff(int** grid, int m, int* gridColSize, int k, int* returnSize,
                 int** returnColumnSizes) {
    int n = gridColSize[0];
    int rows = m - k + 1, cols = n - k + 1;
    int** res = (int**)malloc(rows * sizeof(int*));
    *returnSize = rows;
    *returnColumnSizes = (int*)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) {
        res[i] = (int*)calloc(cols, sizeof(int));
        (*returnColumnSizes)[i] = cols;
    }
    int size = k * k;
    int* kgrid = (int*)malloc(size * sizeof(int));
    for (int i = 0; i + k <= m; i++) {
        for (int j = 0; j + k <= n; j++) {
            int idx = 0;
            for (int x = i; x < i + k; x++) {
                for (int y = j; y < j + k; y++) {
                    kgrid[idx++] = grid[x][y];
                }
            }
            int kmin = INT_MAX;
            qsort(kgrid, size, sizeof(int), cmp);
            for (int t = 1; t < size; t++) {
                if (kgrid[t] == kgrid[t - 1]) {
                    continue;
                }
                kmin = fmin(kmin, kgrid[t] - kgrid[t - 1]);
            }
            if (kmin != INT_MAX) {
                res[i][j] = kmin;
            }
        }
    }
    free(kgrid);
    return res;
}
