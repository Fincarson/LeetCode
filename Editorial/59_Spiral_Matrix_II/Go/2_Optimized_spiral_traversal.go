func generateMatrix(n int) [][]int {
    result := make([][]int, n)
    for i := range result {
        result[i] = make([]int, n)
    }
    dirs := [4][2]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
    d := 0
    row := 0
    col := 0
    cnt := 1
    for cnt <= n*n {
        result[row][col] = cnt
        cnt++
        newRow := (row + dirs[d][0] + n) % n
        newCol := (col + dirs[d][1] + n) % n
        // change direction if next cell is non zero
        if result[newRow][newCol] != 0 {
            d = (d + 1) % 4
        }
        row += dirs[d][0]
        col += dirs[d][1]
    }
    return result
}
