var (
    triangle  [][]int
    memoTable map[string]int
)

func minPath(row int, col int) int {
    params := fmt.Sprintf("%d:%d", row, col)
    if val, ok := memoTable[params]; ok {
        return val
    }
    path := triangle[row][col]
    if row < len(triangle)-1 {
        path += min(minPath(row+1, col), minPath(row+1, col+1))
    }
    memoTable[params] = path
    return path
}

func minimumTotal(triangleInput [][]int) int {
    triangle = triangleInput
    memoTable = make(map[string]int)
    return minPath(0, 0)
}
