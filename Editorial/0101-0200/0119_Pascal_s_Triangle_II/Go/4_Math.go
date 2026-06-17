func getRow(n int) []int {
    row := []int{1}
    for k := 1; k <= n; k++ {
        row = append(row, int(float64(row[len(row)-1]*(n-k+1))/float64(k)))
    }
    return row
}
