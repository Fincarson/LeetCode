class Solution:
    def maximumGap(self, nums):
        if len(nums) < 2:
            return 0

        maxVal = max(nums)
        exp = 1
        radix = 10
        aux = [0] * len(nums)

        while maxVal // exp > 0:
            count = [0] * radix
            for num in nums:
                count[(num // exp) % 10] += 1
            for i in range(1, radix):
                count[i] += count[i - 1]
            i = len(nums) - 1
            while i >= 0:
                aux[count[(nums[i] // exp) % 10] - 1] = nums[i]
                count[(nums[i] // exp) % 10] -= 1
                i -= 1
            for i in range(len(nums)):
                nums[i] = aux[i]
            exp *= 10

        maxGap = 0
        for i in range(len(nums) - 1):
            maxGap = max(nums[i + 1] - nums[i], maxGap)
        return maxGap
