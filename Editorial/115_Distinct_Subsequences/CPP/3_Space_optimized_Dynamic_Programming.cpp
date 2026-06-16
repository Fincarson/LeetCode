class Solution {
public:
    int numDistinct(string s, string t) {
        int M = s.size();
        int N = t.size();
        vector<vector<unsigned int>> dp(M + 1, vector<unsigned int>(N + 1));
        for (int i = 0; i <= M; i++) {
            dp[i][N] = 1;
        }
        for (int j = N - 1; j >= 0; j--) {
            for (int i = M - 1; i >= 0; i--) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        return dp[0][0];
    }
};
