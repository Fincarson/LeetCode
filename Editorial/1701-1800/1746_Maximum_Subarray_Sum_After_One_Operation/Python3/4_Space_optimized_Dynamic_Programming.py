class Solution:
    def maxSumAfterOperation(self, nums: list[int]) -> int:
        n = len(nums)  # Get the size of the input array.

        # Initialize variables to store the maximum sums.
        max_sum_without_square = nums[0]
        max_sum_with_square = nums[0] * nums[0]
        max_sum = max_sum_with_square

        for index in range(1, n):
            # Option 1: Square the current element.
            # Option 2: Add the square of the current element to the previous sum without a square.
            # Option 3: Add the current element to the previous sum with a square.
            max_sum_with_square = max(
                max(
                    nums[index] * nums[index],
                    max_sum_without_square + nums[index] * nums[index],
                ),
                max_sum_with_square + nums[index],
            )

            # Option 1: Start a new subarray.
            # Option 2: Continue the previous subarray.
            max_sum_without_square = max(
                nums[index], max_sum_without_square + nums[index]
            )

            # Update max_sum to track the global maximum sum with exactly one squared element.
            max_sum = max(max_sum, max_sum_with_square)

        return max_sum
