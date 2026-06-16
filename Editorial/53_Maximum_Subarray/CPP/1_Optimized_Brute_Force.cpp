class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_subarray = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int current_subarray = 0;
            for (int j = i; j < nums.size(); j++) {
                current_subarray += nums[j];
                max_subarray = max(max_subarray, current_subarray);
            }
        }
        return max_subarray;
    }
};
