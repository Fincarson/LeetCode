class Solution {
public:
    static constexpr int INF = 1e9;
    int validSubarraySplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if (__gcd(nums[i - 1], nums[j - 1]) > 1) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[n] == INF ? -1 : dp[n];
    }
};
