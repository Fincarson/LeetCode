class Solution {

    public int maxSumAfterOperation(int[] nums) {
        int n = nums.length;

        // Arrays to store the maximum sum of subarrays ending before and starting after each element
        int[] maxLeft = new int[n];
        int[] maxRight = new int[n];

        // No subarray ends before the first element, so set maxLeft[0] to 0
        maxLeft[0] = 0;
        for (int i = 1; i < n; i++) {
            // Compute maxLeft[i]: the maximum subarray sum ending just before nums[i]
            maxLeft[i] = Math.max(maxLeft[i - 1] + nums[i - 1], 0);
        }

        // No subarray starts after the last element, so set maxRight[n - 1] to 0
        maxRight[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            // Compute maxRight[i]: the maximum subarray sum starting just after nums[i]
            maxRight[i] = Math.max(maxRight[i + 1] + nums[i + 1], 0);
        }

        // Initialize the maximum sum as 0
        int maxSum = 0;

        // Iterate over each element in the array
        for (int i = 0; i < n; i++) {
            // Calculate the maximum sum by combining the best left and right subarrays found for each element
            maxSum = Math.max(
                maxSum,
                maxLeft[i] + nums[i] * nums[i] + maxRight[i]
            );
        }

        return maxSum;
    }
}
