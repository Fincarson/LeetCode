func titleToNumber(s string) int {
    result := 0

    alpha_map := make(map[rune]int)
    for i := 0; i < 26; i++ {
        // Decimal 65 in ASCII corresponds to char 'A'
        alpha_map[rune(i+65)] = i + 1
    }

    n := len(s)
    for i := 0; i < n; i++ {
        cur_char := rune(s[n-1-i])
        result += (alpha_map[cur_char] * (pow(26, i)))
    }
    return result
}

// Helper function since Go does not have a built-in power function
func pow(x int, y int) int {
    result := 1
    for i := 0; i < y; i++ {
        result *= x
    }
    return result
}
