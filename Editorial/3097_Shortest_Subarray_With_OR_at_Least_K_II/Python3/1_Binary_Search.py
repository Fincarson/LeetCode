class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        # Binary search on the length of subarray
        left, right = 1, len(nums)
        min_length = -1

        while left <= right:
            mid = left + (right - left) // 2

            if self._has_valid_subarray(nums, k, mid):
                min_length = mid
                right = mid - 1  # Try to find smaller length
            else:
                left = mid + 1  # Try larger length

        return min_length

    def _has_valid_subarray(
        self, nums: list, target_sum: int, window_size: int
    ) -> bool:
        # Tracks count of set bits at each position
        bit_counts = [0] * 32

        # Sliding window approach
        for right in range(len(nums)):
            # Add current number to window
            self._update_bit_counts(bit_counts, nums[right], 1)

            # Remove leftmost number if window exceeds size
            if right >= window_size:
                self._update_bit_counts(
                    bit_counts, nums[right - window_size], -1
                )

            # Check if current window is valid
            if (
                right >= window_size - 1
                and self._convert_bits_to_num(bit_counts) >= target_sum
            ):
                return True

        return False

    def _update_bit_counts(
        self, bit_counts: list, number: int, delta: int
    ) -> None:
        # Update counts for each set bit in the number
        for pos in range(32):
            if number & (1 << pos):
                bit_counts[pos] += delta

    def _convert_bits_to_num(self, bit_counts: list) -> int:
        # Convert bit counts to number using OR operation
        return sum(1 << pos for pos in range(32) if bit_counts[pos])
