int** rotation(int** grid, int gridSize, int* gridColSize, int* returnSize,
               int** returnColumnSizes) {
    int m = gridSize, n = gridColSize[0];
    int** tmp = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        tmp[i] = (int*)malloc(sizeof(int) * m);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            tmp[j][m - 1 - i] = grid[i][j];
        }
    }
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = m;
    }
    return tmp;
}

bool canPartitionGrid(int** grid, int gridSize, int* gridColSize) {
    long long total = 0;
    int m = gridSize, n = gridColSize[0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            total += grid[i][j];
        }
    }
    for (int k = 0; k < 2; k++) {
        long long sum = 0;
        m = gridSize;
        n = gridColSize[0];
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
            }
            if (sum * 2 == total) {
                return true;
            }
        }
        int returnSize, *returnColumnSizes;
        grid = rotation(grid, gridSize, gridColSize, &returnSize,
                        &returnColumnSizes);
        gridSize = returnSize;
        gridColSize = returnColumnSizes;
    }
    return false;
}
