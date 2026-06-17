func strStr(haystack string, needle string) int {
    m := len(needle)
    n := len(haystack)
    if n < m {
        return -1
    }
    // PREPROCESSING
    // longest_border array
    longest_border := make([]int, m)
    longest_border[0] = 0
    // Length of Longest Border for prefix before it.
    prev := 0
    // Iterating from index-1. longest_border[0] will always be 0
    i := 1
    for i < m {
        if needle[i] == needle[prev] {
            // Length of Longest Border Increased
            prev += 1
            longest_border[i] = prev
            i += 1
        } else {
            // Only empty border exist
            if prev == 0 {
                longest_border[i] = 0
                i += 1
            } else {
                // Try finding longest border for this i with reduced prev
                prev = longest_border[prev-1]
            }
        }
    }
    // SEARCHING
    // Pointer for haystack
    haystackPointer := 0
    // Pointer for needle.
    // Also indicates the number of characters matched in the current window.
    needlePointer := 0
    for haystackPointer < n {
        if haystack[haystackPointer] == needle[needlePointer] {
            // Matched Increment Both
            needlePointer += 1
            haystackPointer += 1
            // All characters matched
            if needlePointer == m {
                // m characters behind last matching will be the start of the window
                return haystackPointer - m
            }
        } else {
            if needlePointer == 0 {
                // Zero Matched
                haystackPointer += 1
            } else {
                // Optimally shift left needlePointer. Don't change haystackPointer
                needlePointer = longest_border[needlePointer-1]
            }
        }
    }
    return -1
}
