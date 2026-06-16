func titleToNumber(s string) int {
    result := 0
    n := len(s)
    for i := 0; i < n; i++ {
        result = result * 26
        // In Go, subtracting runes is subtracting ASCII values of characters
        result += (int(s[i]) - int('A') + 1)
    }
    return result
}
