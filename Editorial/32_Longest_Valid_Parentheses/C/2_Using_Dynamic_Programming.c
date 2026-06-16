int longestValidParentheses(char* s) {
    if (!s || strlen(s) <= 0) return 0;
    int sLength = strlen(s);
    int dp[sLength];
    memset(dp, 0, sizeof(int) * sLength);  // initialize all elements as 0
    int maxans = 0;
    for (int i = 1; i < sLength; i++) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                dp[i] = dp[i - 1] +
                        ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }
            maxans = maxans > dp[i] ? maxans : dp[i];
        }
    }
    return maxans;
}
