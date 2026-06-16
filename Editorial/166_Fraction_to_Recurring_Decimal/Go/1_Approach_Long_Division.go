func fractionToDecimal(numerator int, denominator int) string {
    if numerator == 0 {
        return "0"
    }
    var fraction []string
    // If either one is negative (not both)
    if (numerator < 0) != (denominator < 0) {
        fraction = append(fraction, "-")
    }
    // Convert to Long or else abs(-2147483648) overflows
    dividend := absInt(numerator)
    divisor := absInt(denominator)
    fraction = append(fraction, strconv.Itoa(dividend/divisor))
    remainder := dividend % divisor
    if remainder == 0 {
        return strings.Join(fraction, "")
    }
    fraction = append(fraction, ".")
    valMap := make(map[int]int)
    for remainder != 0 {
        if pos, ok := valMap[remainder]; ok {
            fraction = append(
                fraction[:pos],
                append([]string{"("}, append(fraction[pos:], ")")...)...)
            break
        }
        valMap[remainder] = len(fraction)
        remainder *= 10
        fraction = append(fraction, strconv.Itoa(remainder/divisor))
        remainder %= divisor
    }
    return strings.Join(fraction, "")
}

func absInt(val int) int {
    if val < 0 {
        return -val
    }
    return val
}
