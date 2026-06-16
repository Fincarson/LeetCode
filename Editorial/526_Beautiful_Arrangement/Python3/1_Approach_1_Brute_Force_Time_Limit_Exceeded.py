class Solution:
    def __init__(self):
        self.count = 0

    def countArrangement(self, N: int) -> int:
        nums = [i for i in range(1, N + 1)]
        self.permute(nums, 0)
        return self.count

    def permute(self, nums, l):
        if l == len(nums) - 1:
            for i in range(1, len(nums) + 1):
                if nums[i - 1] % i != 0 and i % nums[i - 1] != 0:
                    break
            else:
                self.count += 1
        for i in range(l, len(nums)):
            nums[i], nums[l] = nums[l], nums[i]
            self.permute(nums, l + 1)
            nums[i], nums[l] = nums[l], nums[i]
