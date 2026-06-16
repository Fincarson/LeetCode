class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(amount + 1)); // Use long long to handle large values

        // Initialize the base case: There's one way to make amount 0, which is by not using any coins.
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Populate the dp table.
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i] > j) {
                    dp[i][j] = dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - coins[i]];
                }
            }
        }

        // Check if the final result exceeds the integer limit and return accordingly.
        return dp[0][amount] <= INT_MAX ? dp[0][amount] : -1; // Return -1 if the result exceeds the int limit
    }
};
