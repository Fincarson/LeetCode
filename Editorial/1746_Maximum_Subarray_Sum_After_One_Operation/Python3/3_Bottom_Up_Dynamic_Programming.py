class Solution:
    def maxSumAfterOperation(self, nums: list[int]) -> int:
        n = len(nums)  # Get the size of the input array.

        # Initialize a DP table
        dp = [[0, 0] for _ in range(n)]

        # Base case
        dp[0][0] = nums[
            0
        ]  # Maximum sum with no squared element is just the first element.
        dp[0][1] = (
            nums[0] * nums[0]
        )  # Maximum sum with the first element squared.

        max_sum = dp[0][1]

        for index in range(1, n):
            # Option 1: Start a new subarray.
            # Option 2: Continue the previous subarray.
            dp[index][0] = max(nums[index], dp[index - 1][0] + nums[index])

            # Option 1: Start a new subarray.
            # Option 2: Square the current element.
            # Option 3: Do not square the element.
            dp[index][1] = max(
                max(
                    nums[index] * nums[index],
                    dp[index - 1][0] + nums[index] * nums[index],
                ),
                dp[index - 1][1] + nums[index],
            )

            # Update max_sum
            max_sum = max(max_sum, dp[index][1])

        return max_sum
