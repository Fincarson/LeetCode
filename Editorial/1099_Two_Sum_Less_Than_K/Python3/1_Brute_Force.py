class Solution:
    def twoSumLessThanK(self, nums: List[int], k: int) -> int:
        answer = -1
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                sum = nums[i] + nums[j]
                if sum < k:
                    answer = max(answer, sum)
        return answer
