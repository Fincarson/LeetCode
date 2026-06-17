class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int answer = -1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() && nums[i] < k; i++) {
            auto j = lower_bound(nums.begin() + i + 1, nums.end(), k - nums[i]) - nums.begin() - 1;
            if (j > i) {
                answer = max(answer, nums[i] + nums[j]);
            }
        }
        return answer;
    }
};
