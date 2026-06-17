class Solution {
    public int TrailingZeroes(int n) {
        // Calculate n!
        BigInteger nFactorial = BigInteger.One;
        for (int i = 2; i <= n; i++) {
            nFactorial *= i;
        }

        // Count how many 0's are on the end.
        int zeroCount = 0;

        while (nFactorial % 10 == 0) {
            nFactorial /= 10;
            zeroCount++;
        }

        return zeroCount;
    }
}
