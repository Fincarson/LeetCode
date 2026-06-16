const HALF_INT_MIN int = -1073741824

func divide(dividend int, divisor int) int {
    // Special case: overflow.
    if dividend == -2147483648 && divisor == -1 {
        return 2147483647
    }
    /* We need to convert both numbers to negatives.
     * Also, we count the number of negatives signs. */
    var negatives int = 2
    if dividend > 0 {
        negatives--
        dividend = -dividend
    }
    if divisor > 0 {
        negatives--
        divisor = -divisor
    }
    var quotient int = 0
    /* Once the divisor is bigger than the current dividend,
     * we can't fit any more copies of the divisor into it. */
    for divisor >= dividend {
        /* We know it'll fit at least once as divivend >= divisor.
         * Note: We use a negative powerOfTwo as it's possible we might have
         * the case divide(INT_MIN, -1). */
        var powerOfTwo int = -1
        var value int = divisor
        /* Check if double the current value is too big. If not, continue doubling.
         * If it is too big, stop doubling and continue with the next step */
        for value >= HALF_INT_MIN && value+value >= dividend {
            value += value
            powerOfTwo += powerOfTwo
        }
        // We have been able to subtract divisor another powerOfTwo times.
        quotient += powerOfTwo
        // Remove value so far so that we can continue the process with remainder.
        dividend -= value
    }
    /* If there was originally one negative sign, then
     * the quotient remains negative. Otherwise, switch
     * it to positive. */
    if negatives != 1 {
        return -quotient
    }
    return quotient
}
