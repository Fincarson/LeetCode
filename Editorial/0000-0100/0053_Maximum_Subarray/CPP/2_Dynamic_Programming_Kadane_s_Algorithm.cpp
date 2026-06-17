class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize our variables using the first element.
        int currentSubarray = nums[0];
        int maxSubarray = nums[0];
        // Start with the 2nd element since we already used the first one.
        for (int i = 1; i < nums.size(); i++) {
            // If current_subarray is negative, throw it away. Otherwise, keep
            // adding to it.
            currentSubarray = max(nums[i], currentSubarray + nums[i]);
            maxSubarray = max(maxSubarray, currentSubarray);
        }
        return maxSubarray;
    }
};
