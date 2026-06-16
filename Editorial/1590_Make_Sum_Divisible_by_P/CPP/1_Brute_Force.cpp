class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long totalSum =
            accumulate(nums.begin(), nums.end(), 0LL);  // Use long long for sum

        // If the total sum is already divisible by p, no subarray needs to be
        // removed
        if (totalSum % p == 0) return 0;

        int minLen = n;  // Initialize minLen to the size of the array

        // Try removing every possible subarray
        for (int start = 0; start < n; ++start) {
            long long subSum = 0;  // Use long long to avoid overflow
            for (int end = start; end < n; ++end) {
                subSum += nums[end];  // Calculate the subarray sum

                // Check if removing this subarray makes the remaining sum
                // divisible by p
                long long remainingSum = (totalSum - subSum) % p;

                if (remainingSum == 0) {
                    minLen = min(minLen,
                                 end - start +
                                     1);  // Update the smallest subarray length
                }
            }
        }

        // If no valid subarray is found, return -1
        return minLen == n ? -1 : minLen;
    }
};
