func longestCommonPrefix(strs []string) string {
    if len(strs) == 0 {
        return ""
    }
    minLen := math.MaxInt32
    for _, str := range strs {
        minLen = int(math.Min(float64(minLen), float64(len(str))))
    }
    low, high := 1, minLen
    for low <= high {
        middle := (low + high) / 2
        if isCommonPrefix(strs, middle) {
            low = middle + 1
        } else {
            high = middle - 1
        }
    }
    return strs[0][0 : (low+high)/2]
}

func isCommonPrefix(strs []string, length int) bool {
    str1 := strs[0][0:length]
    for i := 1; i < len(strs); i++ {
        if !strings.HasPrefix(strs[i], str1) {
            return false
        }
    }
    return true
}
