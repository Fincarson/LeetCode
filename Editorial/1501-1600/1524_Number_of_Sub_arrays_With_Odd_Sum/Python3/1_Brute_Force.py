class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        MOD = 1e9 + 7
        n = len(arr)
        count = 0

        # Generate all possible subarrays
        for start_index in range(n):
            current_sum = 0
            # Iterate through each subarray starting at start_index
            for end_index in range(start_index, n):
                current_sum += arr[end_index]
                # Check if the sum is odd
                if current_sum % 2 != 0:
                    count += 1

        return int(count % MOD)
