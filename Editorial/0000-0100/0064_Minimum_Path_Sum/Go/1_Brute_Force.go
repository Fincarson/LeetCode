func calculate(grid [][]int, i int, j int) int {
    if i == len(grid) || j == len(grid[0]) {
        return int(^uint(0) >> 1)
    }
    if i == len(grid)-1 && j == len(grid[0])-1 {
        return grid[i][j]
    }
    return grid[i][j] + min(calculate(grid, i+1, j), calculate(grid, i, j+1))
}

func minPathSum(grid [][]int) int {
    return calculate(grid, 0, 0)
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}
