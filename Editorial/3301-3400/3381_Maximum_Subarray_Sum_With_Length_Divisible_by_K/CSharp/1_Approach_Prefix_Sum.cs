public class Solution {
    public long MaxSubarraySum(int[] nums, int k) {
        int n = nums.Length;
        long prefixSum = 0;
        long maxSum = long.MinValue;
        long[] kSum = new long[k];
        for (int i = 0; i < k; i++) {
            kSum[i] = long.MaxValue / 2;
        }
        kSum[k - 1] = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            maxSum = Math.Max(maxSum, prefixSum - kSum[i % k]);
            kSum[i % k] = Math.Min(kSum[i % k], prefixSum);
        }
        return maxSum;
    }
}
