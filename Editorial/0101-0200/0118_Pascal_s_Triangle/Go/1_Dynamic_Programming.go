func generate(numRows int) [][]int {
    triangle := make([][]int, numRows)
    // Base case; first row is always [1].
    triangle[0] = append(triangle[0], 1)
    for rowNum := 1; rowNum < numRows; rowNum++ {
        row := make([]int, 0)
        prevRow := triangle[rowNum-1]
        // The first row element is always 1.
        row = append(row, 1)
        // Each triangle element (other than the first and last of each row)
        // is equal to the sum of the elements above-and-to-the-left and
        // above-and-to-the-right.
        for j := 1; j < rowNum; j++ {
            row = append(row, prevRow[j-1]+prevRow[j])
        }
        // The last row element is always 1.
        row = append(row, 1)
        triangle[rowNum] = row
    }
    return triangle
}
