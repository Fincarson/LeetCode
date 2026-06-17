class Solution:
    def canJumpFromPosition(self, position, nums):
        if position == len(nums) - 1:
            return True
        furthestJump = min(position + nums[position], len(nums) - 1)
        for nextPosition in range(position + 1, furthestJump + 1):
            if self.canJumpFromPosition(nextPosition, nums):
                return True
        return False

    def canJump(self, nums):
        return self.canJumpFromPosition(0, nums)
