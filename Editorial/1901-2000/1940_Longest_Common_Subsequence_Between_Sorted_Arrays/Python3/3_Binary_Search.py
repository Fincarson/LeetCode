class Solution:
    def longestCommonSubsequence(self, arrays: List[List[int]]) -> List[int]:

        def binary_search(target, nums):
            left = 0
            right = len(nums) - 1
            while left <= right:
                mid = left + (right - left) // 2
                if nums[mid] > target:
                    right = mid - 1
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    return True
            return False

        shortestArray = arrays[0]
        for array in arrays:
            if len(array) < len(shortestArray):
                shortestArray = array

        longest_common_subseq = shortestArray

        for array in arrays:
            # There are no elements that are common to all of the arrays
            if len(longest_common_subseq) == 0:
                return longest_common_subseq
            uncommon = []

            # Remove any elements from the longest common subsequence
            # that are not in current array
            for num in longest_common_subseq:
                if not binary_search(num, array):
                    uncommon.append(num)
            for num in uncommon:
                longest_common_subseq.remove(num)

        return longest_common_subseq
