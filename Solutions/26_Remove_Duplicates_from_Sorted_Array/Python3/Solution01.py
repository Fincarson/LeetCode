class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if(len(nums) == 0): return 0

        result = 0
        j = 0

        for i in range(1, len(nums)):
            if(nums[j] != nums[i]):
                nums[j+1] = nums[i]
                j += 1
                result += 1
        
        return result + 1