func divide(dividend int, divisor int) int {
    HALF_INT_MIN := -1073741824
    // Special cases: overflow.
    if dividend == -2147483648 && divisor == -1 {
        return 2147483647
    }
    if dividend == -2147483648 && divisor == 1 {
        return -2147483648
    }
    /* We need to convert both numbers to negatives.
     * Also, we count the number of negatives signs. */
    negatives := 2
    if dividend > 0 {
        negatives--
        dividend = -dividend
    }
    if divisor > 0 {
        negatives--
        divisor = -divisor
    }
    /* We want to find the largest doubling of the divisor in the negative 32-bit
     * integer range that could fit into the dividend.
     * Note if it would cause an overflow by being less than HALF_INT_MIN,
     * then we just stop as we know double it would not fit into INT_MIN anyway. */
    maxBit := 0
    for divisor >= HALF_INT_MIN && divisor+divisor >= dividend {
        maxBit++
        divisor += divisor
    }
    quotient := 0
    for bit := maxBit; bit >= 0; bit-- {
        if divisor >= dividend {
            quotient -= 1 << uint(bit)
            dividend -= divisor
        }
        divisor = (divisor + 1) >> 1
    }
    /* If there was originally one negative sign, then
     * the quotient remains negative. Otherwise, switch
     * it to positive. */
    if negatives != 1 {
        quotient = -quotient
    }
    return quotient
}
