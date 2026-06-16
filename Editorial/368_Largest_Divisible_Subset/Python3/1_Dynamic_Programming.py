class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # The container that holds all intermediate solutions.
        # key: the largest element in a valid subset.
        subsets = {-1: set()}

        for num in sorted(nums):
            subsets[num] = max(
                [subsets[k] for k in subsets if num % k == 0], key=len
            ) | {num}

        return list(max(subsets.values(), key=len))
