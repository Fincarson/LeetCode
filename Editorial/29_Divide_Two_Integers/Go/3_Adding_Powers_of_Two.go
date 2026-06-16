func divide(dividend int, divisor int) int {
    const HalfIntMin = -1073741824
    // Special case: overflow.
    if dividend == -2147483648 && divisor == -1 {
        return 2147483647
    }
    // We need to convert both numbers to negatives.
    // Also, we count the number of negatives signs.
    negatives := int8(2)
    if dividend > 0 {
        negatives--
        dividend = -dividend
    }
    if divisor > 0 {
        negatives--
        divisor = -divisor
    }
    doubles := make([]int, 0, 32)
    powersOfTwo := make([]int, 0, 32)
    // Nothing too exciting here, we're just making a list of doubles of the divisor
    // and the corresponding power of 2
    powerOfTwo := 1
    for divisor >= dividend {
        doubles = append(doubles, divisor)
        powersOfTwo = append(powersOfTwo, powerOfTwo)
        // prevent needless overflow
        if divisor < HalfIntMin {
            break
        }
        divisor += divisor
        powerOfTwo += powerOfTwo
    }
    quotient := 0
    // Go from largest double to smallest, checking if the current double fits into the remainder of the dividend
    for i := len(doubles) - 1; i >= 0; i-- {
        if doubles[i] >= dividend {
            quotient += powersOfTwo[i]
            dividend -= doubles[i]
        }
    }
    // if there was originally one negative sign, then the quotient remains negative. Otherwise, switch it to positive
    if negatives == 1 {
        return -quotient
    }
    return quotient
}
