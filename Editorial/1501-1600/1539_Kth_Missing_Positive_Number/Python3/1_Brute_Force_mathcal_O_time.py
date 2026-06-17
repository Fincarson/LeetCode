class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        for num in arr:
            if num <= k:
                k += 1
            elif num > k:
                break
        return k
