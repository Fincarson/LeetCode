int uniquePaths(int m, int n) {
    int** arr;
    arr = malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) arr[i] = malloc(n * sizeof(int));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 1;
        }
    }
    for (int col = 1; col < m; ++col) {
        for (int row = 1; row < n; ++row) {
            arr[col][row] = arr[col - 1][row] + arr[col][row - 1];
        }
    }
    return arr[m - 1][n - 1];
}
