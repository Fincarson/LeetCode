class Solution:
    def containsNearbyAlmostDuplicate(
        self, nums: List[int], k: int, t: int
    ) -> bool:
        for i in range(len(nums)):
            for j in range(max(i - k, 0), i):
                if abs(nums[i] - nums[j]) <= t:
                    return True
        return False
