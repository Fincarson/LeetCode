function minPathSum(grid: number[][]): number {
    let dp: number[] = new Array(grid[0].length).fill(0);
    for (let i = grid.length - 1; i >= 0; i--) {
        for (let j = grid[0].length - 1; j >= 0; j--) {
            if (i == grid.length - 1 && j != grid[0].length - 1)
                dp[j] = grid[i][j] + dp[j + 1];
            else if (j == grid[0].length - 1 && i != grid.length - 1)
                dp[j] = grid[i][j] + dp[j];
            else if (i != grid.length - 1 && j != grid[0].length - 1)
                dp[j] = grid[i][j] + Math.min(dp[j], dp[j + 1]);
            else dp[j] = grid[i][j];
        }
    }
    return dp[0];
}
