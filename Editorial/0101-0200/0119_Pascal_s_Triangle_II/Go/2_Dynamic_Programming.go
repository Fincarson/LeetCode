type key struct {
    row int
    col int
}

var cache = make(map[key]int)

func getNum(row int, col int) int {
    rowCol := key{row, col}
    if val, ok := cache[rowCol]; ok {
        return val
    }
    if row == 0 || col == 0 || row == col {
        cache[rowCol] = 1
        return 1
    }
    cache[rowCol] = getNum(row-1, col-1) + getNum(row-1, col)
    return cache[rowCol]
}

func getRow(rowIndex int) []int {
    ans := make([]int, rowIndex+1)
    for i := range ans {
        ans[i] = getNum(rowIndex, i)
    }
    return ans
}
