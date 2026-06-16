int numDistinct(char* s, char* t) {
    int len1 = strlen(s);
    int len2 = strlen(t);
    if (len1 < len2) return 0;
    int i, j;
    unsigned long long int dp[1001][1001];
    dp[0][0] = 1;
    for (i = 1; i <= len2; ++i) dp[0][i] = 0;
    for (i = 1; i <= len1; ++i) dp[i][0] = 1;
    for (i = 1; i <= len1; ++i)
        for (j = 1; j <= len2; ++j)
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
    return dp[len1][len2];
}
