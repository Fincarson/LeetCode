class Solution {
public:
    int numDecodings(string s) {
        // DP array to store the subproblem results
        vector<int> dp(s.length() + 1);
        dp[0] = 1;

        // Ways to decode a string of size 1 is 1. Unless the string is '0'.
        // '0' doesn't have a single digit decode.
        dp[1] = s[0] == '0' ? 0 : 1;

        for (size_t i = 2; i < dp.size(); i++) {
            // Check if successful single digit decode is possible.
            if (s[i - 1] != '0') {
                dp[i] = dp[i - 1];
            }

            // Check if successful two digit decode is possible.
            int two_digit = stoi(s.substr(i - 2, 2));
            if (two_digit >= 10 && two_digit <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[s.length()];
    }
};
