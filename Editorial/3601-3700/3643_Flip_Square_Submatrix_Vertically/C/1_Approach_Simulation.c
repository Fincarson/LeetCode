int** reverseSubmatrix(int** grid, int gridSize, int* gridColSize, int x, int y,
                       int k, int* returnSize, int** returnColumnSizes) {
    for (int i0 = x, i1 = x + k - 1; i0 < i1; ++i0, --i1) {
        for (int j = y; j < y + k; ++j) {
            int temp = grid[i0][j];
            grid[i0][j] = grid[i1][j];
            grid[i1][j] = temp;
        }
    }
    *returnSize = gridSize;
    *returnColumnSizes = gridColSize;
    return grid;
}
