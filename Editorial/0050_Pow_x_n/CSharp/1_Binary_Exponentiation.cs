public class Solution {
    private double BinaryExp(double x, long n) {
        // Base case, to stop recursive calls.
        if (n == 0) {
            return 1;
        }

        // Handle case where, n < 0.
        if (n < 0) {
            return 1.0 / BinaryExp(x, -1 * n);
        }

        // Perform Binary Exponentiation.
        // If 'n' is odd we perform Binary Exponentiation on 'n - 1' and
        // multiply result with 'x'.
        if (n % 2 == 1) {
            return x * BinaryExp(x * x, (n - 1) / 2);
        }
        // Otherwise we calculate result by performing Binary Exponentiation on
        // 'n'.
        else {
            return BinaryExp(x * x, n / 2);
        }
    }

    public double MyPow(double x, int n) {
        // Call recursive function with correct types.
        return BinaryExp(x, (long)n);
    }
}
