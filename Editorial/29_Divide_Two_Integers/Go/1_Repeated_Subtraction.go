func divide(dividend int, divisor int) int {
    if dividend == math.MinInt32 && divisor == -1 {
        return math.MaxInt32
    }
    negatives := 2
    if dividend > 0 {
        negatives--
        dividend = -dividend
    }
    if divisor > 0 {
        negatives--
        divisor = -divisor
    }
    quotient := 0
    for dividend-divisor <= 0 {
        dividend -= divisor
        quotient--
    }
    if negatives != 1 {
        return -quotient
    }
    return quotient
}
