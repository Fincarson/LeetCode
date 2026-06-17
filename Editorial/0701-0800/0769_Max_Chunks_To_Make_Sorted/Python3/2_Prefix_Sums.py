class Solution:
    def maxChunksToSorted(self, arr: list[int]) -> int:
        n = len(arr)
        chunks = 0
        prefix_sum = 0
        sorted_prefix_sum = 0

        # Iterate over the array
        for i in range(n):
            # Update prefix sum of `arr`
            prefix_sum += arr[i]
            # Update prefix sum of the sorted array
            sorted_prefix_sum += i

            # If the two sums are equal, the two prefixes contain the same elements; a chunk can be formed
            if prefix_sum == sorted_prefix_sum:
                chunks += 1

        return chunks
