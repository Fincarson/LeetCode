class Solution(object):
    def countArrangement(self, N):
        """
        :type N: int
        :rtype: int
        """
        self.count = 0
        nums = [i + 1 for i in range(N)]
        self.permute(nums, 0)
        return self.count

    def permute(self, nums, l):
        if l == len(nums):
            self.count += 1
        for i in range(l, len(nums)):
            nums[i], nums[l] = nums[l], nums[i]
            if nums[l] % (l + 1) == 0 or (l + 1) % nums[l] == 0:
                self.permute(nums, l + 1)
            nums[i], nums[l] = nums[l], nums[i]
