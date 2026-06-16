class Solution {

    public int maxSumAfterOperation(int[] nums) {
        int n = nums.length;
        // Initialize a DP table to store results of subproblems.
        int[][] dp = new int[n][2];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1); // Initialize all entries to -1.
        }

        // Create array to pass be reference
        int maxSum[] = new int[1];
        maxSum[0] = 0;

        // Call the recursive helper function to compute the result.
        getMaxSumHelper(0, nums, true, dp, maxSum);
        return maxSum[0];
    }

    private int getMaxSumHelper(
        int index,
        int[] nums,
        boolean canSquare,
        int[][] dp,
        int[] maxSum
    ) {
        if (index == nums.length) {
            return 0; // Base case: if we reach the end of the array, return 0.
        }

        // If the result is already computed for this state, return it.
        if (dp[index][canSquare ? 1 : 0] != -1) {
            return dp[index][canSquare ? 1 : 0];
        }

        // Case 1: Skip squaring the current element.
        int nextSumWithoutSquare = getMaxSumHelper(
            index + 1,
            nums,
            canSquare,
            dp,
            maxSum
        );
        int maxSumWithoutSquare = nums[index]; // The value itself if we don't square it.
        if (nextSumWithoutSquare > 0) {
            maxSumWithoutSquare += nextSumWithoutSquare; // Accumulate if positive.
        }

        // Case 2: Square the current element if allowed.
        int maxSumWithSquare = 0;
        if (canSquare) {
            maxSumWithSquare = nums[index] * nums[index]; // Square the current element.
            int nextSumWithSquare = getMaxSumHelper(
                index + 1,
                nums,
                false,
                dp,
                maxSum
            ); // Don't square further.
            if (nextSumWithSquare > 0) {
                maxSumWithSquare += nextSumWithSquare; // Accumulate if positive.
            }
        }

        // Update the global maxSum if we find a better one.
        maxSum[0] = Math.max(
            maxSum[0],
            Math.max(maxSumWithSquare, maxSumWithoutSquare)
        );

        // Store the result in dp table and return the maximum of the two options.
        dp[index][canSquare ? 1 : 0] = Math.max(
            maxSumWithSquare,
            maxSumWithoutSquare
        );
        return dp[index][canSquare ? 1 : 0];
    }
}
