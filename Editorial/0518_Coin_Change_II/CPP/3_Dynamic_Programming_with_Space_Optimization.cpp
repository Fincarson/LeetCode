class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long long> dp(amount + 1); // Use unsigned long long to handle large values
        dp[0] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]]; // This will now use unsigned long long for addition
            }
        }

        return dp[amount] <= INT_MAX ? dp[amount] : -1; // Return -1 if the result exceeds the maximum int value
    }
};
