func convert(s string, numRows int) string {
    if numRows == 1 {
        return s
    }

    var answer strings.Builder
    n := len(s)
    charsInSection := 2 * (numRows - 1)

    for currRow := 0; currRow < numRows; currRow++ {
        index := currRow
        for index < n {
            answer.WriteByte(s[index])

            // If current row is not first or last,
            // then we have to add one more character of current section.
            if currRow != 0 && currRow != numRows-1 {
                charsInBetween := charsInSection - 2*currRow
                secondIndex := index + charsInBetween
                if secondIndex < n {
                    answer.WriteByte(s[secondIndex])
                }
            }
            // Jump to same row's first character of next section.
            index += charsInSection
        }
    }
    return answer.String()
}
