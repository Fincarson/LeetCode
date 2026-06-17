class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int n = nums.length;
        int result = 0;
        HashSet set = new HashSet<>();
        for (int start = 0; start < n; start++) {
            // reset set and current sum for next subarray
            set.clear();
            int currentSum = 0;
            for (int end = start; end < n && !set.contains(nums[end]); end++) {
                currentSum += nums[end];
                set.add(nums[end]);
            }
            // update result with maximum sum found so far
            result = Math.max(result, currentSum);
        }
        return result;
    }
}
