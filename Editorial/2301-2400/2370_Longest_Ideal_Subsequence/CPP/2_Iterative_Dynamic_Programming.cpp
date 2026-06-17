class Solution {
public:
    int longestIdealString(string s, int k) {
        int N = s.size();
        vector<int> dp(26, 0);

        int res = 0;
        // Updating dp with the i-th character
        for (int i = 0; i < N; i++) {
            int curr = s[i] - 'a';
            int best = 0;
            for (int prev = max(0, curr - k); prev < min(26, curr + k + 1); prev++) {
                best = max(best, dp[prev]);
            }

            // Append s[i] to the previous longest ideal subsequence
            dp[curr] = best + 1;
            res = max(res, dp[curr]);
        }

        return res;
    }
};
