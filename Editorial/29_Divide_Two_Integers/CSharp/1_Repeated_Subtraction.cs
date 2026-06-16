public class Solution {
    public int Divide(int dividend, int divisor) {
        // Special case: overflow.
        if (dividend == int.MinValue && divisor == -1) {
            return int.MaxValue;
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
            quotient--;
            dividend -= divisor;
        }

        /* If there was originally one negative sign, then
         * the quotient remains negative. Otherwise, switch
         * it to positive. */
        if (negatives != 1) {
            quotient = -quotient;
        }

        return quotient;
    }
}
