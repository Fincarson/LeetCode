class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> jumps = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {3, 9, 0},
            {},
            {1, 7, 0},
            {2, 6},
            {1, 3},
            {2, 4}
        };

        int MOD = 1e9 + 7;
        vector<int> dp(10, 0);
        vector<int> prevDp(10, 1);

        for (int remain = 1; remain < n; remain++) {
            dp = vector(10, 0);
            for (int square = 0; square < 10; square++) {
                int ans = 0;
                for (int nextSquare : jumps[square]) {
                    ans = (ans + prevDp[nextSquare]) % MOD;
                }

                dp[square] = ans;
            }
            
            prevDp = dp;
        }

        int ans = 0;
        for (int square = 0; square < 10; square++) {
            ans = (ans + prevDp[square]) % MOD;
        }

        return ans;
    }
};
