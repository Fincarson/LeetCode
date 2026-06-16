// C solution
int minPathSum(int** grid, int gridSize, int* gridColSize) {
    for (int i = gridSize - 1; i >= 0; i--) {
        for (int j = gridColSize[0] - 1; j >= 0; j--) {
            if (i == gridSize - 1 && j != gridColSize[0] - 1)
                grid[i][j] += grid[i][j + 1];
            else if (j == gridColSize[0] - 1 && i != gridSize - 1)
                grid[i][j] += grid[i + 1][j];
            else if (j != gridColSize[0] - 1 && i != gridSize - 1)
                grid[i][j] += grid[i + 1][j] < grid[i][j + 1] ? grid[i + 1][j]
                                                              : grid[i][j + 1];
        }
    }
    return grid[0][0];
}
