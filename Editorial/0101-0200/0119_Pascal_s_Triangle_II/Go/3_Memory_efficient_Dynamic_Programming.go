func getRow(rowIndex int) []int {
    row := make([]int, rowIndex+1)
    for i := 0; i < rowIndex+1; i++ {
        row[i] = 1
    }
    for i := 1; i < rowIndex; i++ {
        for j := i; j > 0; j-- {
            row[j] += row[j-1]
        }
    }
    return row
}
