func shortestWay(source string, target string) int {
    // List of indices for all characters in source
    charToIndices := make([][]int, 26)
    for i := 0; i < len(source); i++ {
        c := source[i]
        if charToIndices[c-'a'] == nil {
            charToIndices[c-'a'] = make([]int, 0)
        }
        charToIndices[c-'a'] = append(charToIndices[c-'a'], i)
    }

    // Pointer for source
    sourceIterator := 0

    // Number of times we need to iterate through source
    count := 1

    // Find all characters of target in source
    for _, c := range target {
        // If the character is not in the source, return -1
        if charToIndices[c-'a'] == nil {
            return -1
        }

        // Binary search to find the index of the character in source
        // next to the source iterator
        indices := charToIndices[c-'a']
        index := sort.Search(len(indices), func(i int) bool {
            return indices[i] >= sourceIterator
        })

        // If we have reached the end of the list, we need to iterate
        // through source again, hence first index of character in source.
        if index == len(indices) {
            count++
            sourceIterator = indices[0] + 1
        } else {
            sourceIterator = indices[index] + 1
        }
    }

    // Return the number of times we need to iterate through source
    return count
}
