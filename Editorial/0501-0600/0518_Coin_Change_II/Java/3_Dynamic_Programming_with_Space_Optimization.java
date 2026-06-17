class Solution {
    public int change(int amount, int[] coins) {
        int n = coins.length;
        long[] dp = new long[amount + 1]; // Use long to avoid overflow
        dp[0] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }

        return dp[amount] <= Integer.MAX_VALUE ? (int) dp[amount] : -1; // Return -1 if result exceeds int limit
    }
}
