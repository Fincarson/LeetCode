public class Solution {
    private const int HALF_INT_MIN = -1073741824;  // -2**30;

    public int Divide(int dividend, int divisor) {
        // Special case: overflow.
        if (dividend == int.MinValue && divisor == -1) {
            return int.MaxValue;
        }

        /* We need to convert both numbers to negatives.
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

        List<int> doubles = new List<int>();
        List<int> powersOfTwo = new List<int>();
        /* Nothing too exciting here, we're just making a list of doubles of 1
         * and the divisor. This is pretty much the same as Approach 2, except
         * we're actually storing the values this time. */
        int powerOfTwo = -1;
        while (divisor >= dividend) {
            doubles.Add(divisor);
            powersOfTwo.Add(powerOfTwo);
            // Prevent needless overflows from occurring...
            if (divisor < HALF_INT_MIN) {
                break;
            }

            divisor += divisor;
            powerOfTwo += powerOfTwo;
        }

        int quotient = 0;
        /* Go from largest double to smallest, checking if the current double
         * fits. into the remainder of the dividend. */
        for (int i = doubles.Count - 1; i >= 0; i--) {
            if (doubles[i] >= dividend) {
                // If it does fit, add the current powerOfTwo to the quotient.
                quotient += powersOfTwo[i];
                // Update dividend to take into account the bit we've now
                // removed.
                dividend -= doubles[i];
            }
        }

        /* If there was originally one negative sign, then
         * the quotient remains negative. Otherwise, switch
         * it to positive. */
        if (negatives != 1) {
            return -quotient;
        }

        return quotient;
    }
}
