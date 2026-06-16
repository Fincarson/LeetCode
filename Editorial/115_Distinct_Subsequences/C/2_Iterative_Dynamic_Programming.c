// C
unsigned int numDistinct(char* s, char* t) {
    int M = strlen(s);
    int N = strlen(t);
    unsigned int dp[M + 1][N + 1];
    memset(dp, 0, sizeof(dp));  // Initialize all dp elements to 0
    // Base case initialization
    for (int i = 0; i <= M; ++i) dp[i][N] = 1;
    for (int i = M - 1; i >= 0; --i) {
        for (int j = N - 1; j >= 0; --j) {
            if (s[i] == t[j])
                dp[i][j] = dp[i + 1][j] + dp[i + 1][j + 1];
            else
                dp[i][j] = dp[i + 1][j];
        }
    }
    return dp[0][0];
}
