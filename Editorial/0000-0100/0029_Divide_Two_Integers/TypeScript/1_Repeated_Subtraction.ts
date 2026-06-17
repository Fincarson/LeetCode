function divide(dividend: number, divisor: number): number {
    // Constants.
    const MAX_INT = 2147483647; // 2**31 - 1
    const MIN_INT = -2147483648; // -2**31
    // Special case: overflow.
    if (dividend === MIN_INT && divisor === -1) {
        return MAX_INT;
    }
    // We need to convert both numbers to negatives
    // for the reasons explained above.
    // Also, we count the number of negatives signs.
    let negatives = 2;
    if (dividend > 0) {
        negatives -= 1;
        dividend = -dividend;
    }
    if (divisor > 0) {
        negatives -= 1;
        divisor = -divisor;
    }
    // Count how many times the divisor has to be
    // added to get the dividend. This is the quotient.
    let quotient = 0;
    while (dividend - divisor <= 0) {
        quotient -= 1;
        dividend -= divisor;
    }
    // If there was originally one negative sign, then
    // the quotient remains negative. Otherwise, switch
    // it to positive.
    return negatives != 1 ? -quotient : quotient;
}
