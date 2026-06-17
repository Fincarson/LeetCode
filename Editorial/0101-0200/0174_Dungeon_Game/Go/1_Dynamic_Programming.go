func calculateMinimumHP(dungeon [][]int) int {
    rows, cols := len(dungeon), len(dungeon[0])
    dp := make([][]int, rows)
    for i := 0; i < rows; i++ {
        dp[i] = make([]int, cols)
        for j := 0; j < cols; j++ {
            dp[i][j] = 1<<31 - 1
        }
    }

    get_min_health := func(currCell int, nextRow int, nextCol int) int {
        if nextRow >= rows || nextCol >= cols {
            return 1<<31 - 1
        }
        nextCell := dp[nextRow][nextCol]
        // hero needs at least 1 point to survive
        return max(1, nextCell-currCell)
    }

    for row := rows - 1; row >= 0; row-- {
        for col := cols - 1; col >= 0; col-- {
            currCell := dungeon[row][col]

            right_health := get_min_health(currCell, row, col+1)
            down_health := get_min_health(currCell, row+1, col)
            next_health := min(right_health, down_health)

            min_health := 0
            if next_health != 1<<31-1 {
                min_health = next_health
            } else {
                if currCell >= 0 {
                    min_health = 1
                } else {
                    min_health = 1 - currCell
                }
            }

            dp[row][col] = min_health
        }
    }

    return dp[0][0]
}

func min(a int, b int) int {
    if a < b {
        return a
    }
    return b
}

func max(a int, b int) int {
    if a > b {
        return a
    }
    return b
}
