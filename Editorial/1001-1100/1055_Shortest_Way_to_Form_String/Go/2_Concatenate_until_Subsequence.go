func shortestWay(source string, target string) int {

    // Boolean array to mark all characters of source
    sourceChars := make([]bool, 26)
    for _, c := range source {
        sourceChars[c - 'a'] = true
    }

    // Check if all characters of target are present in source
    // If any character is not present, return -1
    for _, c := range target {
        if !sourceChars[c - 'a'] {
            return -1
        }
    }

    // Concatenate source until target is a subsequence of concatenated string
    concatenatedSource := source
    count := 1
    for !isSubsequence(target, concatenatedSource) {
        concatenatedSource += source
        count++
    }

    // Number of concatenations done
    return count
}

// To check if toCheck is a subsequence of inString
func isSubsequence(toCheck string, inString string) bool {
    i, j := 0, 0
    for i < len(toCheck) && j < len(inString) {
        if toCheck[i] == inString[j] {
            i++
        }
        j++
    }

    return i == len(toCheck)
}
