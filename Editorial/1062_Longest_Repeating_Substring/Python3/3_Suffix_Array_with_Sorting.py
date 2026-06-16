class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        length = len(s)
        suffixes = []

        # Create suffix array by storing all suffixes of the string
        for i in range(length):
            suffixes.append(s[i:])
        # Sort the suffix array
        suffixes.sort()

        max_length = 0
        # Compare adjacent suffixes to find the longest common prefix
        for i in range(1, length):
            j = 0
            # Compare characters one by one until
            # they differ or end of one suffix is reached
            while (
                j < min(len(suffixes[i]), len(suffixes[i - 1]))
                and suffixes[i][j] == suffixes[i - 1][j]
            ):
                j += 1
            # Update max_length with the length of the common prefix
            max_length = max(max_length, j)
        return max_length
