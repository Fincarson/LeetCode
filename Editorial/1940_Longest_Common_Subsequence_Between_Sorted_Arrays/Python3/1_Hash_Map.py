class Solution:
    def longestCommonSubsequence(self, arrays: List[List[int]]) -> List[int]:
        frequencies = defaultdict(int)
        longest_common_subseq = []

        # Count the frequency of each number across all arrays
        for array in arrays:
            for num in array:
                frequencies[num] += 1
                # Num is in all of the arrays
                if frequencies[num] == len(arrays):
                    longest_common_subseq.append(num)

        return longest_common_subseq
