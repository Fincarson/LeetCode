int calculate(int** grid, int gridSize, int* gridColSize, int i, int j) {
    if (i == gridSize || j == gridColSize[0]) return INT_MAX;
    if (i == gridSize - 1 && j == gridColSize[0] - 1) return grid[i][j];
    return grid[i][j] + fmin(calculate(grid, gridSize, gridColSize, i + 1, j),
                             calculate(grid, gridSize, gridColSize, i, j + 1));
}
int minPathSum(int** grid, int gridSize, int* gridColSize) {
    return calculate(grid, gridSize, gridColSize, 0, 0);
}
