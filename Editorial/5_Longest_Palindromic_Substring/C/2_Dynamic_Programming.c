#include <stdbool.h>
#include <string.h>

char* longestPalindrome(char* s) {
    int n = strlen(s);
    bool dp[n][n];
    memset(dp, false, sizeof dp);
    int ans[2] = {0, 0};

    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            ans[0] = i;
            ans[1] = i + 1;
        } else {
            dp[i][i + 1] = false;
        }
    }

    for (int diff = 2; diff < n; ++diff) {
        for (int i = 0; i < n - diff; ++i) {
            int j = i + diff;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                ans[0] = i;
                ans[1] = j;
            } else {
                dp[i][j] = false;
            }
        }
    }

    s[ans[1] + 1] = '\0';
    return s + ans[0];
}
