func romanToInt(s string) int {
    values := map[rune]int{
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000,
    }

    total := 0
    i := 0
    for i < len(s) {
        // If this is the subtractive case.
        if i+1 < len(s) && values[rune(s[i])] < values[rune(s[i+1])] {
            total += values[rune(s[i+1])] - values[rune(s[i])]
            i += 2
        } else {
            total += values[rune(s[i])]
            i += 1
        }
    }
    return total
}
