class Solution(object):
    def canJump(self, nums):
        GOOD, BAD, UNKNOWN = 1, 0, -1
        memo = [UNKNOWN] * len(nums)
        memo[-1] = GOOD
        for i in range(len(nums) - 2, -1, -1):
            furthest_jump = min(i + nums[i], len(nums) - 1)
            for j in range(i + 1, furthest_jump + 1):
                if memo[j] == GOOD:
                    memo[i] = GOOD
                    break
        return memo[0] == GOOD
