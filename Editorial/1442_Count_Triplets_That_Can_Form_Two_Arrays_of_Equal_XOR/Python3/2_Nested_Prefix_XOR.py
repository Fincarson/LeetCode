class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        prefix_XOR = [0] + arr[:]
        size = len(prefix_XOR)

        # Perform XOR on consecutive elements in the modified array
        for i in range(1, size):
            prefix_XOR[i] ^= prefix_XOR[i - 1]

        count = 0

        # Iterate through the modified array to count triplets
        for start in range(size):
            for end in range(start + 1, size):
                if prefix_XOR[start] == prefix_XOR[end]:
                    # Increment the result by the count of valid triplets
                    count += end - start - 1

        return count
