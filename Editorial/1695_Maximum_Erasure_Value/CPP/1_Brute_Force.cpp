class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), result = 0;
        unordered_set<int> seen;
        for (int start = 0; start < n; start++) {
            // reset seen and current sum for next subarray
            seen.clear();
            int currentSum = 0;
            for (int end = start; end < n && (seen.find(nums[end]) == seen.end());
                 end++) {
                currentSum += nums[end];
                seen.insert(nums[end]);
            }
            // update result with maximum sum found so far
            result = max(result, currentSum);
        }
        return result;
    }
};
