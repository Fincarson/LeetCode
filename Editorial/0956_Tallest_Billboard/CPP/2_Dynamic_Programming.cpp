class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        // dp[taller - shorter] = taller
        map<int, int> dp;
        dp[0] = 0;

        for (int r : rods) {
            // Creating a copy of dp (new_dp) means we don't add r to these
            // stands.
            map<int, int> new_dp(dp);

            for (auto entry : dp) {
                int diff = entry.first;
                int taller = entry.second;
                int shorter = taller - diff;

                // Add r to the taller stand, thus the height difference is
                // increased to diff + r.
                int new_taller =
                    new_dp.count(diff + r) > 0 ? new_dp[diff + r] : 0;
                new_dp[diff + r] = max(new_taller, taller + r);

                // Add r to the shorter stand, the height difference is
                // expressed as abs(shorter + r - taller).
                int new_diff = abs(shorter + r - taller);
                int new_taller2 = max(shorter + r, taller);
                new_dp[new_diff] =
                    max(new_taller2,
                        new_dp.count(new_diff) > 0 ? new_dp[new_diff] : 0);
            }

            dp = new_dp;
        }

        // Return the maximum height with 0 difference.
        return dp.count(0) > 0 ? dp[0] : 0;
    }
};
