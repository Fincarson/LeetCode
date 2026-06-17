func convert(s string, numRows int) string {
    if numRows == 1 {
        return s
    }

    n := len(s)
    sections := int(math.Ceil(float64(n) / float64(2*numRows-2)))
    numCols := sections * (numRows - 1)

    matrix := make([][]rune, numRows)
    for i := range matrix {
        matrix[i] = make([]rune, numCols)
        for j := range matrix[i] {
            matrix[i][j] = ' '
        }
    }

    currRow, currCol, currStringIndex := 0, 0, 0

    // Iterate in zig-zag pattern on matrix and fill it with string characters.
    for currStringIndex < n {
        // Move down.
        for currRow < numRows && currStringIndex < n {
            matrix[currRow][currCol] = rune(s[currStringIndex])
            currRow++
            currStringIndex++
        }

        currRow -= 2
        currCol++

        // Move up (with moving right also).
        for currRow > 0 && currCol < numCols && currStringIndex < n {
            matrix[currRow][currCol] = rune(s[currStringIndex])
            currRow--
            currCol++
            currStringIndex++
        }
    }

    answer := make([]rune, 0)
    for _, row := range matrix {
        for _, character := range row {
            if character != ' ' {
                answer = append(answer, character)
            }
        }
    }

    return string(answer)
}
