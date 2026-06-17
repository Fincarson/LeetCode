long long max(long long a, long long b) { return a > b ? a : b; }

long long maximumProfit(int* prices, int pricesSize, int k) {
    int n = pricesSize;
    long long dp[n][k + 1][3];
    memset(dp, 0, sizeof(dp));

    // initialize the state on day 0
    for (int j = 1; j <= k; j++) {
        dp[0][j][1] = -(long long)prices[0];
        dp[0][j][2] = (long long)prices[0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j][0] = max(
                dp[i - 1][j][0],
                max(dp[i - 1][j][1] + prices[i], dp[i - 1][j][2] - prices[i]));
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][0] + prices[i]);
        }
    }

    return dp[n - 1][k][0];
}
