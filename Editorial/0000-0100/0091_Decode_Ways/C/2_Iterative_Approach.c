int numDecodings(char* s) {
    // DP array to store the subproblem results
    int sLength = strlen(s);
    int dp[sLength + 1];
    dp[0] = 1;
    // Ways to decode a string of size 1 is 1. Unless the string is '0'.
    // '0' doesn't have a single digit decode.
    dp[1] = s[0] == '0' ? 0 : 1;
    for (int i = 2; i < sLength + 1; i++) {
        dp[i] = 0;
        // Check if successful single digit decode is possible.
        if (s[i - 1] != '0') {
            dp[i] = dp[i - 1];
        }
        char twoDigitStr[3];
        strncpy(twoDigitStr, &s[i - 2], 2);
        twoDigitStr[2] = '\0';
        int twoDigit = atoi(twoDigitStr);
        // Check if successful two digit decode is possible.
        if (twoDigit >= 10 && twoDigit <= 26) {
            dp[i] += dp[i - 2];
        }
    }
    return dp[sLength];
}
