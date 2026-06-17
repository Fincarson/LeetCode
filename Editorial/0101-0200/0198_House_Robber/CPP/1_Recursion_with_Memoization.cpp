class Solution {
public:
    vector<int> memo;

    int rob(vector<int>& nums) {
        memo.resize(100, -1);

        return robFrom(0, nums);
    }

private:
    int robFrom(int i, vector<int>& nums) {
        // No more houses left to examine.
        if (i >= nums.size()) {
            return 0;
        }

        // Return cached value.
        if (memo[i] > -1) {
            return memo[i];
        }

        // Recursive relation evaluation to get the optimal answer.
        int ans = max(robFrom(i + 1, nums), robFrom(i + 2, nums) + nums[i]);

        // Cache for future use.
        memo[i] = ans;
        return ans;
    }
};
