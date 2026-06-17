class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        total_sum = sum(nums)

        # If the total sum is already divisible by p, no subarray needs to be removed
        if total_sum % p == 0:
            return 0

        n = len(nums)
        min_len = n  # Initialize min_len to the size of the array

        # Try removing every possible subarray
        for start in range(n):
            sub_sum = 0
            for end in range(start, n):
                sub_sum += nums[end]  # Calculate the subarray sum

                # Check if removing this subarray makes the remaining sum divisible by p
                remaining_sum = (total_sum - sub_sum) % p

                if remaining_sum == 0:
                    min_len = min(
                        min_len, end - start + 1
                    )  # Update the smallest subarray length

        # If no valid subarray is found, return -1
        return min_len if min_len != n else -1
