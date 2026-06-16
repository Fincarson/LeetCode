func shortestWay(source string, target string) int {

    // Length of source
    sourceLength := len(source)

    // Next Occurrence of Character after Index
    nextOccurrence := make([][]int, sourceLength)
    for idx := range nextOccurrence {
        nextOccurrence[idx] = make([]int, 26)
    }

    // Base Case
    for c := 0; c < 26; c++ {
        nextOccurrence[sourceLength - 1][c] = -1
    }
    nextOccurrence[sourceLength - 1][source[sourceLength - 1] - 'a'] = sourceLength - 1

    // Fill using recurrence relation
    for idx := sourceLength - 2; idx >= 0; idx-- {
        for c := 0; c < 26; c++ {
            nextOccurrence[idx][c] = nextOccurrence[idx + 1][c]
        }
        nextOccurrence[idx][source[idx] - 'a'] = idx
    }

    // Pointer to the current index in source
    sourceIterator := 0

    // Number of times we need to iterate through source
    count := 1

    // Find all characters of target in source
    for _, c := range target {

        // If the character is not present in source
        if nextOccurrence[0][c - 'a'] == -1 {
            return -1
        }

        // If we have reached the end of source, or the character is not in
        // source after source_iterator, loop back to beginning
        if sourceIterator == sourceLength || nextOccurrence[sourceIterator][c - 'a'] == -1 {
            count++
            sourceIterator = 0
        }

        // Next occurrence of character in source after source_iterator
        sourceIterator = nextOccurrence[sourceIterator][c - 'a'] + 1
    }

    // Return the number of times we need to iterate through source
    return count
}
