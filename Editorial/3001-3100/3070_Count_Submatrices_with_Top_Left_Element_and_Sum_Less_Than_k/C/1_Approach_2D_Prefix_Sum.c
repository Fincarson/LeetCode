int countSubmatrices(int** grid, int gridSize, int* gridColSize, int k) {
    int m = gridSize;
    int n = *gridColSize;
    int* cols = (int*)calloc(n, sizeof(int));
    int res = 0;

    for (int i = 0; i < m; i++) {
        int rows = 0;
        for (int j = 0; j < n; j++) {
            cols[j] += grid[i][j];
            rows += cols[j];
            if (rows <= k) {
                res++;
            }
        }
    }

    free(cols);
    return res;
}
