class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        longest_sequence = 0
        for left in range(len(nums)):
            num_zeroes = 0
            for right in range(left, len(nums)):   # Check every consecutive sequence
                if num_zeroes == 2:
                    break
                if nums[right] == 0:               # Count how many 0's
                    num_zeroes += 1
                if num_zeroes <= 1:                 # Update answer if it's valid
                    longest_sequence = max(longest_sequence, right - left + 1)
        return longest_sequence
