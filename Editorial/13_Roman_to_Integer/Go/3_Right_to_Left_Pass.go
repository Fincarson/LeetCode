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
    var lastValue int = int(values[rune(s[len(s)-1])])
    var total int = lastValue

    for i := len(s) - 2; i >= 0; i-- {
        var currentValue int = int(values[rune(s[i])])
        if currentValue < lastValue {
            total -= currentValue
        } else {
            total += currentValue
        }
        lastValue = currentValue
    }
    return total
}
