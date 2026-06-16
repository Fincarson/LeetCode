class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> ans(n);
        for (size_t i = 0; i < n; i++) {
            ans[i] = nums[i] * nums[i];
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
