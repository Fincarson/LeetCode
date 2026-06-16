class Solution {

    public int maxSumAfterOperation(int[] nums) {
        int n = nums.length; // Get the size of the input array.

        // Initialize variables to store the maximum sums.
        int maxSumWithoutSquare = nums[0];
        int maxSumWithSquare = nums[0] * nums[0];
        int maxSum = maxSumWithSquare;

        for (int index = 1; index < n; index++) {
            // Option 1: Square the current element.
            // Option 2: Add the square of the current element to the previous sum without a square.
            // Option 3: Add the current element to the previous sum with a square.
            maxSumWithSquare = Math.max(
                Math.max(
                    nums[index] * nums[index],
                    maxSumWithoutSquare + nums[index] * nums[index]
                ),
                maxSumWithSquare + nums[index]
            );

            // Option 1: Start a new subarray.
            // Option 2: Continue the previous subarray.
            maxSumWithoutSquare = Math.max(
                nums[index],
                maxSumWithoutSquare + nums[index]
            );

            // Update maxSum
            maxSum = Math.max(maxSum, maxSumWithSquare);
        }

        return maxSum;
    }
}
