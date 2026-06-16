int divide(int dividend, int divisor) {
    // Special case: overflow.
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    /* We need to convert both numbers to negatives
     * for the reasons explained above.
     * Also, we count the number of negatives signs. */
    int negatives = 2;
    if (dividend > 0) {
        negatives--;
        dividend = -dividend;
    }
    if (divisor > 0) {
        negatives--;
        divisor = -divisor;
    }
    /* Count how many times the divisor has to be added
     * to get the dividend. This is the quotient. */
    int quotient = 0;
    while (dividend - divisor <= 0) {
        dividend -= divisor;
        quotient--;
    }
    /* If there was originally one negative sign, then
     * the quotient remains negative. Otherwise, switch
     * it to positive. */
    if (negatives != 1) {
        return -quotient;
    }
    return quotient;
}
