bool isInterleave(char* s1, char* s2, char* s3) {
    int len1 = strlen(s1), len2 = strlen(s2), len3 = strlen(s3);
    if (len3 != len1 + len2) {
        return false;
    }
    bool dp[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = true;
            } else if (i == 0) {
                dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
            } else if (j == 0) {
                dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
            } else {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                           (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
    }
    return dp[len1][len2];
}
