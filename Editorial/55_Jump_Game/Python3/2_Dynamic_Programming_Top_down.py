class Solution:
    def __init__(self):
        self.memo = []
        self.nums = []

    def canJumpFromPosition(self, position):
        if self.memo[position] != -1:
            return self.memo[position] == 1
        furthestJump = min(position + self.nums[position], len(self.nums) - 1)
        for nextPosition in range(position + 1, furthestJump + 1):
            if self.canJumpFromPosition(nextPosition):
                self.memo[position] = 1
                return True
        self.memo[position] = 0
        return False

    def canJump(self, nums):
        self.nums = nums
        self.memo = [-1] * len(nums)  # -1 for unknown, 0 for bad, 1 for good
        self.memo[-1] = 1  # The last position is always "good"
        return self.canJumpFromPosition(0)
