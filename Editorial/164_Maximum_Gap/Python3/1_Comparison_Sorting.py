class Solution:
    def maximumGap(self, nums):
        if (
            nums is None or len(nums) < 2
        ):  # check if array is empty or small sized
            return 0

        nums.sort()  # sort the array

        maxGap = 0

        for i in range(len(nums) - 1):
            maxGap = max(nums[i + 1] - nums[i], maxGap)

        return maxGap
