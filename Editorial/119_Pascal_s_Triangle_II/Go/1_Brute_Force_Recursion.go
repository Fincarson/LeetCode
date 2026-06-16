func getNum(row int, col int) int {
    if row == 0 || col == 0 || row == col {
        return 1
    }
    return getNum(row-1, col-1) + getNum(row-1, col)
}

func getRow(rowIndex int) []int {
    ans := make([]int, rowIndex+1)
    for i := 0; i <= rowIndex; i++ {
        ans[i] = getNum(rowIndex, i)
    }
    return ans
}
