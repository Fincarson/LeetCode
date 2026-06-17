class Solution {
    public int numberOfWays(String corridor) {
        // Store 1000000007 in a variable for convenience
        final int MOD = 1_000_000_007;

        // Initial values of three variables
        int zero = 0;
        int one = 0;
        int two = 1;

        // Compute using derived equations
        for (char thing : corridor.toCharArray()) {
            if (thing == 'S') {
                zero = one;
                int temp = one;
                one = two;
                two = temp;
            } else {
                two = (two + zero) % MOD;
            }
        }

        // Return the result
        return zero;
    }
}
