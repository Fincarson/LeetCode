class Solution:
    def maxSumAfterOperation(self, nums):
        n = len(nums)
        # Initialize a DP table to store results of subproblems.
        dp = [[-1, -1] for _ in range(n)]

        max_sum = [0]

        # Call the recursive helper function to compute the result.
        self._get_max_sum_helper(0, nums, True, dp, max_sum)

        return max_sum[0]

    def _get_max_sum_helper(self, index, nums, can_square, dp, max_sum):
        if index == len(nums):
            return 0  # Base case: if we reach the end of the array, return 0.

        # If the result is already computed for this state, return it.
        if dp[index][1 if can_square else 0] != -1:
            return dp[index][1 if can_square else 0]

        # Case 1: Skip squaring the current element.
        next_sum_without_square = self._get_max_sum_helper(
            index + 1, nums, can_square, dp, max_sum
        )
        max_sum_without_square = nums[
            index
        ]  # The value itself if we don't square it.
        if next_sum_without_square > 0:
            max_sum_without_square += (
                next_sum_without_square  # Accumulate if positive.
            )

        # Case 2: Square the current element if allowed.
        max_sum_with_square = 0
        if can_square:
            max_sum_with_square = (
                nums[index] * nums[index]
            )  # Square the current element.
            next_sum_with_square = self._get_max_sum_helper(
                index + 1, nums, False, dp, max_sum
            )  # Don't square further.
            if next_sum_with_square > 0:
                max_sum_with_square += (
                    next_sum_with_square  # Accumulate if positive.
                )

        # Update the global max_sum if we find a better one.
        max_sum[0] = max(
            max_sum[0], max(max_sum_with_square, max_sum_without_square)
        )

        # Store the result in dp table and return the maximum of the two options.
        dp[index][1 if can_square else 0] = max(
            max_sum_with_square, max_sum_without_square
        )
        return dp[index][1 if can_square else 0]
