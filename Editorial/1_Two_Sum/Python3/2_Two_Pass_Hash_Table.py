class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}

        for i, num in enumerate(nums):
            seen[num] = i

        for i, num in enumerate(nums):
            complement = target - num
            if complement in seen and seen[complement] != i:
                return [i, seen[complement]]

        return []
